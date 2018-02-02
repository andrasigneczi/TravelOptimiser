#pragma once

#ifndef _TIMETABLE_H
#define _TIMETABLE_H

#include <string>
#include <map>
#include <vector>
#include "Duration.h"
#include "Date.h"

class Rule {
private:

	enum RuleType {
		UNDEFINED,
		DAY_INTERVALL, // Monday-Friday
		DATE_INTERVAL, // 2017.05.01 - 2018.06.02
		
	};
	
	Rule() : mCharRule(0) {}
	
public:
	enum Day {
		Monday,
		Tuesday,
		Wednesday,
		Thursday,
		Friday,
		Saturday,
		Sunday,
		Undefined
	};
	
	enum DayType {
		Workday,
		PublicHoliday,
	};
	
	// Rule validity interval
	Rule( std::string from, std::string to ); // "2017.05.01", "2017.05.01"
	
	// Assigning special character to a weekday, a weekday interval or a weekday interval with day type.
	Rule( char sign, Day day ); // e.g.: ('X', Saturday)
	Rule( char sign, Day from, Day to ); // e.g.: ('A', Monday,Friday)
	Rule( char sign, Day from, Day to, DayType type ); // e.g.: ('A', Monday,Friday, Workday)
	
	// Assigning time interval with period to a weekday, weekday interval or a weekday interval with day type
	Rule( Day day, std::string t1, std::string t2, Duration period ); // (Saturday, "5:59", "22:59", 30_min)
	Rule( Day from, Day to, std::string t1, std::string t2, Duration period ); // (Monday, Saturday, "5:59", "22:59", 30_min)
	Rule( Day from, Day to, DayType type, std::string t1, std::string t2, Duration period ); // (Monday, Saturday, Workday, "5:59", "22:59", 30_min)

	// returns true, if the rule is applicable for this day, e.g. date="2018.01.03", and the rule is Monday-Saturday Workday
	bool isApplicable( Date date ) const;
	
	// generates datetime string vector based on the parameter date and the rule.
	std::vector<std::string> extract( Date date ) const;
	
//private:
	char mCharRule;
	std::string mDateIntervalBegin; // "2017.05.01"
	std::string mDateIntervalEnd; // "2018.05.01"
	std::string mTimeBegin; // "5:25"
	std::string mTimeEnd; // "6:25"
	Day mDayIntervalBegin; // Monday
	Day mDayIntervalEnd; // Saturday
	DayType  mDayType; // Workday, PublicHoliday
	Duration mShortPeriod; // 30_min
};

class Timetable {
public:
	struct Data {
		Data(double price, time_t timeConsuming ) : mPrice( price ), mTimeConsuming( timeConsuming ) { }
		double mPrice;
		time_t mTimeConsuming;
	};
	typedef std::map<time_t, Data> TimetableData;

	// The basic way of definition of a timetable: adding every single departure one by one
	void add(std::string departure, double price, Duration timeConsuming);
	
	// Second way of defining a timetable: defining rules, and adding to the timetable with departures and fixed time and price.
	void add(Rule rule);
	void add(std::vector<std::string> departures);
	
	double getPrice(time_t departure) const;
	time_t getTimeConsuming(time_t departure) const;
	//const double getFirstPrice() const;
	const TimetableData& getTimetable() const { return mTimetable;}

	void correctionByTimezone(std::string timeZone);

	// for planning backwards
	time_t searchLessBeginningPlusTimeConsuming(time_t currentTime) const;
	// for planning forwards
	std::pair<time_t, time_t> searchGreaterBeginning(time_t currentTime) const;

	void setFixPrice( double x );
	double getFixPrice() { return mFixPrice; }
	void setFixTravellingTime( Duration d );
	Duration getFixTravellingTime() { return mFixTravellingTime; }
	bool extractRules();

private:
	std::map<time_t, Data> mTimetable;
	std::map<std::string, Data> mTempTimetable;
	double mFixPrice;
	Duration mFixTravellingTime;
	std::vector<Rule> mRules;
	std::vector<std::string> mDepartureTimeRules;
};
#endif