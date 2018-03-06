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
	mDayIntervalBegin = UndefinedDay;
	mDayIntervalEnd = UndefinedDay;
	mDayType = UndefinedDayType;
}

// Assigning special character to a weekday, a weekday interval or a weekday interval with day type.
Rule::Rule( char sign, Rule::Day day ) { // e.g.: ('X', Saturday)
	mCharRule = sign;
	mDayIntervalBegin = day;
	mDayIntervalEnd = day;
	mDayType = UndefinedDayType;
}

Rule::Rule( char sign, Rule::Day from, Rule::Day to ) { // e.g.: ('A', Monday,Friday)
	mCharRule = sign;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mDayType = UndefinedDayType;
	
	if( mDayIntervalBegin > mDayIntervalEnd ) {
		std::cerr << "Rule mDayIntervalBegin > mDayIntervalEnd\n";
		assert( 0 );
	}
}

Rule::Rule( char sign, Rule::Day from, Rule::Day to, DayType type ) { // e.g.: ('A', Monday,Friday, Workday)
	mCharRule = sign;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mDayType = type; // Workday, PublicHoliday

	if( mDayIntervalBegin > mDayIntervalEnd ) {
		std::cerr << "Rule mDayIntervalBegin > mDayIntervalEnd\n";
		assert( 0 );
	}
}

// Assigning time interval with period to a weekday, weekday interval or a weekday interval with day type
Rule::Rule( Rule::Day day, std::string t1, std::string t2, Duration period ) { // (Saturday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = day;
	mDayIntervalEnd = day;
	mShortPeriod = period;
	mDayType = UndefinedDayType;

	if( mDayIntervalBegin > mDayIntervalEnd ) {
		std::cerr << "Rule mDayIntervalBegin > mDayIntervalEnd\n";
		assert( 0 );
	}
}

Rule::Rule( Rule::Day from, Rule::Day to, std::string t1, std::string t2, Duration period ) { // (Monday, Saturday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mShortPeriod = period;
	mDayType = UndefinedDayType;

	if( mDayIntervalBegin > mDayIntervalEnd ) {
		std::cerr << "Rule mDayIntervalBegin > mDayIntervalEnd\n";
		assert( 0 );
	}
}

Rule::Rule( Rule::Day from, Rule::Day to, Rule::DayType type, std::string t1, std::string t2, Duration period ) { // (Monday, Saturday, Workday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = from;
	mDayIntervalEnd = to;
	mShortPeriod = period;
	mDayType = type;

	if( mDayIntervalBegin > mDayIntervalEnd ) {
		std::cerr << "Rule mDayIntervalBegin > mDayIntervalEnd\n";
		assert( 0 );
	}
}

Rule::Rule( DayType type, std::string t1, std::string t2, Duration period ) { // (PublicHoliday, "5:59", "22:59", 30_min)
	mCharRule = 0;
	mTimeBegin = t1;
	mTimeEnd = t2;
	mDayIntervalBegin = UndefinedDay;
	mDayIntervalEnd = UndefinedDay;
	mShortPeriod = period;
	mDayType = type;
}

bool Rule::isApplicable( Date date, const std::set<Date>& publicHolidays, const std::set<Date>& extraWorkdays ) const {
	//Day mDayIntervalBegin; // Monday
	//Day mDayIntervalEnd; // Saturday
	//DayType  mDayType; // Workday, PublicHoliday

	// special handling of the dateinterval rules
	if( mDateIntervalBegin.length() > 0 && mDateIntervalEnd.length() > 0
	    && mDayIntervalBegin == UndefinedDay
	    && mDayIntervalEnd == UndefinedDay
	    && mDayType == UndefinedDayType ) {
	    	return false;
	}

	// day order: Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
	if( mDayType == Workday && ((Day)date.getWDay() == Saturday || (Day)date.getWDay() == Sunday ) && extraWorkdays.find( date ) != extraWorkdays.end()) {
	} else {
		// 1. I don't check the thegin and end day interval, so I have to call with a date in this interval.
		// 2. Which weekday is this?
		if( mDayIntervalBegin != UndefinedDay && date.getWDay() < (int)mDayIntervalBegin ) {
			return false;
		}
		if( mDayIntervalEnd != UndefinedDay && date.getWDay() > (int)mDayIntervalEnd ) {
			return false;
		}
	}
	if( mDayType != Workday && ((Day)date.getWDay() == Saturday || (Day)date.getWDay() == Sunday ) && extraWorkdays.find( date ) != extraWorkdays.end()) {
		return false;
	}
	
	// Workday can be different, depending on the recent calendar, e.g. Ester, Christmas, ...
	// The Saturday and the Sunday are considered as public holiday by default
	
	// Public holiday, if:
	// it is weekend and it isn't in the extra workdays set
	// it isn't weekend and it is in the public holidays set
	bool dateIsPublicHoliday = (( date.getWDay() == 6 || date.getWDay() == 0 ) && extraWorkdays.find( date ) == extraWorkdays.end());

	//if( dateIsPublicHoliday ) {
	//	std::cerr << "Rule::isApplicable public holiday 1: " << date << "\n";
	//}

	dateIsPublicHoliday |= (!( date.getWDay() == 6 || date.getWDay() == 0 ) && publicHolidays.find( date ) != publicHolidays.end());

	//if( dateIsPublicHoliday ) {
	//	std::cerr << "Rule::isApplicable public holiday 2: " << date << "\n";
	//}

	//if( publicHolidays.find( date ) != publicHolidays.end()) {
	//	std::cerr << "Rule::isApplicable public holiday 3: " << date << "\n";
	//}
	
	if( mDayType == Workday && dateIsPublicHoliday ) {
		return false;
	}
	
	if( mDayType == PublicHoliday && !dateIsPublicHoliday ) {
		return false;
	}
	
	// We cannot use the Saturday schedule for extra working days
//	if( mDayType != Workday && (Day)date.getWDay() == Saturday && extraWorkdays.find( date ) != extraWorkdays.end()) {
//		std::cerr << "Rule is not Applicable on: " << date << "\n";
//		std::cerr << "rule: " << (int)mDayType << "\n";
//		return false;
//	}
		
//	if( date.getYear() == 2018 && date.getMonth()==1 && date.getDay() == 6 ) {
//		std::cerr << "Rule::isApplicable date: " << date << "\n";
//		std::cerr << "Rule::isApplicable wday: " << date.getWDay() << "\n";
//		if( extraWorkdays.find( date ) != extraWorkdays.end()) {
//			std::cerr << "Rule::isApplicable date is in the extraWorkdays set\n";
//		}
//	}

	return true;
}

// generates datetime string vector based on the parameter date and the rule.
std::vector<std::string> Rule::extract( Date date, const std::vector<std::string>& departures ) const {
	std::vector<std::string> result;
	
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
		for( time_t i = begin; i <= end; i += step ) {
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
	mTempTimetable.emplace(departure, Data(price, timeConsuming.getSec()));
}

void Timetable::add(Rule rule) {
	mRules.push_back( rule );
}

void Timetable::add(std::vector<std::string> departures) {
	mDepartureTimeRules = departures;
}

void Timetable::add(std::vector<Duration> durations) {
	mDurationTimeRules = durations;
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

void Timetable::setDefaultTravelingTime( Duration d ) {
	mDefaultTravelingTime = d;
}

bool Timetable::extractRules() {
	
	Date dateIntervalBegin; // "2017-05-01"
	Date dateIntervalEnd; // "2018-05-01"
	
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
	for( Date x = dateIntervalBegin; x <= dateIntervalEnd; ++x ) {
		size_t addedTimeCountPerDay = 0;
		for( const Rule& r : mRules ) {
			if( r.isApplicable( x, mPublicHolidays, mExtraWorkdays )) {
    			std::vector<std::string> departures = r.extract( x, mDepartureTimeRules );
    			for( auto d : departures ) {
    				if( mDurationTimeRules.size() > addedTimeCountPerDay ) {
    					add( d, getFixPrice(), mDurationTimeRules[addedTimeCountPerDay]);
    				} else {
    					add( d, getFixPrice(), getDefaultTravelingTime());
    				}
    				++addedTimeCountPerDay;
    			}
			}
		}
	}
	
	return true;
}

void Timetable::addPublicHolidays( const std::vector<std::string>& publicHolidays ) {
	for( auto& x : publicHolidays ) {
		mPublicHolidays.insert( Date( x ));
	}
	
	//for( auto& x : mPublicHolidays ) {
	//	std::cerr << "Timetable::addPublicHolidays: " << x << std::endl;
	//}
}//

void Timetable::addExtraWorkdays( const std::vector<std::string>& extraWorkdays ) {
	for( auto& x : extraWorkdays ) {
		mExtraWorkdays.insert( Date( x ));
	}
}
