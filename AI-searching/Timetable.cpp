#include "Timetable.h"

void Timetable::add(std::string departure, double price) {
	mTimetable.emplace(departure, price);
}

const double Timetable::getPrice(std::string time) const {
	auto it = mTimetable.find(time);
	if (it == mTimetable.end())
		return -1.0;
	return it->second;
}

const double Timetable::getFirstPrice() const {
	if (mTimetable.size() > 0) {
		return mTimetable.begin()->second;
	}
	return -1.0;
}