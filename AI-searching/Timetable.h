#pragma once

#ifndef _TIMETABLE_H
#define _TIMETABLE_H

#include <string>
#include <map>

class Timetable {

public:
	void add(std::string departure, double price);
	const double getPrice(std::string time) const;
	const double getFirstPrice() const;

private:
	std::map<std::string, double> mTimetable;
};
#endif