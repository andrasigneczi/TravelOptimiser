#pragma once

#ifndef _TIMETABLE_H
#define _TIMETABLE_H

#include <string>
#include <map>
#include "Duration.h"

class Timetable {
public:
	struct Data {
		Data(double price, time_t timeConsuming ) : mPrice( price ), mTimeConsuming( timeConsuming ) { }
		double mPrice;
		time_t mTimeConsuming;
	};
	typedef std::map<time_t, Data> TimetableData;

	void add(std::string departure, double price, Duration timeConsuming);
	const double getPrice(time_t departure) const;
	const time_t getTimeConsuming(time_t departure) const;
	//const double getFirstPrice() const;
	const TimetableData& getTimetable() const { return mTimetable;}

	void correctionByTimezone(std::string timeZone);

	// for planning backwards
	time_t searchLessBeginningPlusTimeConsuming(time_t currentTime) const;
	// for planning forwards
	std::pair<time_t, time_t> searchGreaterBeginning(time_t currentTime) const;

private:
	std::map<time_t, Data> mTimetable;
	std::map<std::string, Data> mTempTimetable;
};
#endif