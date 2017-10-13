#pragma once

#ifndef _TIMETABLE_H
#define _TIMETABLE_H

#include <string>
#include <map>
#include "Duration.h"

class Timetable {
public:
	struct Data {
		Data(double price, double timeConsuming ) : mPrice( price ), mTimeConsuming( timeConsuming ) { }
		double mPrice;
		double mTimeConsuming;
	};
	typedef std::map<time_t, Data> TimetableData;

	void add(std::string departure, double price, double timeConsuming );
	void add(std::string departure, double price, Duration timeConsuming);
	const double getPrice(time_t departure) const;
	const double getTimeConsuming(time_t departure) const;
	//const double getFirstPrice() const;
	const TimetableData& getTimetable() const { return mTimetable;}

	void correctionByTimezone(std::string timeZone);

private:
	std::map<time_t, Data> mTimetable;
	std::map<std::string, Data> mTempTimetable;
};
#endif