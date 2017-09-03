#pragma once

#ifndef _TIMETABLE_H
#define _TIMETABLE_H

#include <string>
#include <map>

class Timetable {
public:
	struct Data {
		Data(double price, double timeConsuming ) : mPrice( price ), mTimeConsuming( timeConsuming ) { }
		double mPrice;
		double mTimeConsuming;
	};
	typedef std::map<time_t, Data> TimetableData;

	void add(std::string departure, double price, double timeConsuming );
	const double getPrice(time_t departure) const;
	//const double getFirstPrice() const;
	const TimetableData& getTimetable() const { return mTimetable;}

private:
	std::map<time_t, Data> mTimetable;
};
#endif