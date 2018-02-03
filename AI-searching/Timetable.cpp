#include "Timetable.h"
#include "Backtrack.h"
#include <assert.h>
#include "TimeHelper.h"
#include "Date.h"

/***********************************************************************************************************************************/
/******************************************************* RULE **********************************************************************/
/***********************************************************************************************************************************/

// Rule validity interval
Rule::Rule( std::string from, std::string to ) { // "2017.05.01", "2017.05.01"
    mCharRule = 0;
	mDateIntervalBegin = from;
	mDateIntervalEnd = to;
	mDayIntervalBegin = Undefined;
	mDayIntervalEnd = Undefined;
}

// Assigning special character to a weekday, a weekday interval or a weekday interval with day type.
Rule::Rule( char sign, Rule::Day day ) { // e.g.: ('X', Saturday)
	mCharRule = sign;
	mDayIntervalBegin = day;
	mDayIntervalEnd = day;
}

Rule::Rule( char sign, Rule::Day from, Rule::Day to ) { // e.g.: ('A', Monday,Friday)
	mCharRule = sign;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
}

Rule::Rule( char sign, Rule::Day from, Rule::Day to, DayType type ) { // e.g.: ('A', Monday,Friday, Workday)
	mCharRule = sign;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mDayType = type; // Workday, PublicHoliday
}

// Assigning time interval with period to a weekday, weekday interval or a weekday interval with day type
Rule::Rule( Rule::Day day, std::string t1, std::string t2, Duration period ) { // (Saturday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = day;
	mDayIntervalEnd = day;
	mShortPeriod = period;
}

Rule::Rule( Rule::Day from, Rule::Day to, std::string t1, std::string t2, Duration period ) { // (Monday, Saturday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mShortPeriod = period;
}

Rule::Rule( Rule::Day from, Rule::Day to, Rule::DayType type, std::string t1, std::string t2, Duration period ) { // (Monday, Saturday, Workday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mShortPeriod = period;
	mDayType = type;
}

bool Rule::isApplicable( Date date ) const {
	//Day mDayIntervalBegin; // Monday
	//Day mDayIntervalEnd; // Saturday
	//DayType  mDayType; // Workday, PublicHoliday
	
	// 1. I don't check the thegin and end day interval, so I have to call with a date in this interval.
	// 2. Which weekday is this?
	if( mDayIntervalBegin != Undefined && date.getWDay() - 1 < (int)mDayIntervalBegin ) {
		return false;
	}
	
	if( mDayIntervalEnd != Undefined && date.getWDay() - 1 > (int)mDayIntervalEnd ) {
		return false;
	}
	
	// Workday can be defferent, depending on the recent calendar, e.g. Ester, Christmas, ...
	if( mDayType == Workday && date.getWDay() >= 6 ) {
		return false;
	}
	
	return true;
}

// generates datetime string vector based on the parameter date and the rule.
std::vector<std::string> Rule::extract( Date date, const std::vector<std::string>& departures ) const {
	std::vector<std::string> result;
	
	if(  mDayIntervalBegin == Undefined || mDayIntervalEnd == Undefined ) {
		return result;
	}
	
	char datetime[100];
	if( mCharRule != 0 && departures.size() > 0 ) {
		int hour, min;
		for( auto& t : departures ) {
			if( t[ 0 ] == mCharRule ) {
				hour = 0;
				min = 0;
				TimeHelper::parseStringTime( t, hour, min );
				sprintf( datetime, "%04d-%02d-%02d %02d:%02d", date.getYear(), date.getMonth(), date.getDay(), hour, min );
				result.push_back( datetime );
			}
		}
	} else if( mTimeBegin.length() > 0 && mTimeEnd.length() > 0 && mShortPeriod > 0_min ) {
		int hourBeg = 0;
		int minBeg  = 0;
		int hourEnd = 0;
		int minEnd  = 0;
		TimeHelper::parseStringTime( mTimeBegin, hourBeg, minBeg );
		TimeHelper::parseStringTime( mTimeEnd, hourEnd, minEnd );
		
		time_t begin = hourBeg * 3600 + minBeg * 60;
		time_t end   = hourEnd * 3600 + minEnd * 60;
		time_t step = mShortPeriod.getSec();
		for( time_t i = begin; i < end; i += step ) {
			int hour = i / 3600;
			int min = ( i % 3600 ) / 60;
			sprintf( datetime, "%04d-%02d-%02d %02d:%02d", date.getYear(), date.getMonth(), date.getDay(), hour, min );
			result.push_back( datetime );
		}
	}
	return result;
}

/***********************************************************************************************************************************/
/************************************************** TIMETABLE **********************************************************************/
/***********************************************************************************************************************************/
void Timetable::add(std::string departure, double price, Duration timeConsuming) {
	//mTimetable.emplace(Backtrack::stringToTime(departure), Data(price, timeConsuming));
	mTempTimetable.emplace(departure, Data(price, timeConsuming.getSec()));
}

void Timetable::add(Rule rule) {
	mRules.push_back( rule );
}

void Timetable::add(std::vector<std::string> departures) {
	mDepartureTimeRules = departures;
}

double Timetable::getPrice(time_t departure) const {
	auto it = mTimetable.find(departure);
	if (it == mTimetable.end())
		return -1.0;
	return it->second.mPrice;
}

time_t Timetable::getTimeConsuming(time_t departure) const {
	auto it = mTimetable.find(departure);
	assert(it != mTimetable.end());
		if (it == mTimetable.end()) {
		return -1;
	}
	return it->second.mTimeConsuming;
}

/*
const double Timetable::getFirstPrice() const {
	if (mTimetable.size() > 0) {
		return mTimetable.begin()->second.mPrice;
	}
	return -1.0;
}
*/

void Timetable::correctionByTimezone(std::string timeZone) {
	extractRules();
	for (auto pair : mTempTimetable) {
		size_t pos = pair.first.find("+");
		if (pos == std::string::npos) {
			mTimetable.emplace(TimeHelper::stringToTime(pair.first+timeZone), Data(pair.second.mPrice, pair.second.mTimeConsuming));
		}
		else {
			mTimetable.emplace(TimeHelper::stringToTime(pair.first), Data(pair.second.mPrice, pair.second.mTimeConsuming));
		}
	}
}

// for planning backwards
time_t Timetable::searchLessBeginningPlusTimeConsuming(time_t currentTime) const {
	time_t retVal = 0;
	for (auto pair : mTimetable) {
		time_t val = pair.first + pair.second.mTimeConsuming;
		if (val < currentTime) {
			retVal = pair.first;
		}
		else {
			break;
		}
	}
	return retVal;
}

// for planning forwards
std::pair<time_t, time_t> Timetable::searchGreaterBeginning(time_t currentTime) const {
	for (auto pair : mTimetable) {
		if (pair.first > currentTime) {
			return std::pair<time_t, time_t>(pair.first, pair.second.mTimeConsuming);
		}
	}
	return std::pair < time_t, time_t>(0, 0);
}

void Timetable::setFixPrice( double x ) {
	mFixPrice = x;
}

void Timetable::setFixTravellingTime( Duration d ) {
	mFixTravellingTime = d;
}

bool Timetable::extractRules() {
	
	Date dateIntervalBegin; // "2017.05.01"
	Date dateIntervalEnd; // "2018.05.01"
	for( const Rule& r : mRules ) {
		if( r.mDateIntervalBegin.length() == 10 && r.mDateIntervalEnd.length() == 10 ) {
			dateIntervalBegin = r.mDateIntervalBegin;
			dateIntervalEnd = r.mDateIntervalEnd;
		}
	}
	
	// 0. mDateIntervalBegin and mDateIntervalEnd are mandatory, let's check it.
	if( dateIntervalBegin.isNull() || dateIntervalEnd.isNull()) {
		return false;
	}
	
	// 2. Iteration from mDateIntervalBegin to mDateIntervalEnd and apply the rules.
	for( Date x = dateIntervalBegin; x < dateIntervalEnd; ++x ) {
		for( const Rule& r : mRules ) {
			if( r.isApplicable( x )) {
    			std::vector<std::string> departures = r.extract( x, mDepartureTimeRules );
    			for( auto d : departures ) {
    				add( d, getFixPrice(), getFixTravellingTime());
    			}
			}
		}
	}
	return true;
}
