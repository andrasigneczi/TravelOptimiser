#include "Timetable.h"
#include "Backtrack.h"

void Timetable::add(std::string departure, double price, double timeConsuming) {
	//mTimetable.emplace(Backtrack::stringToTime(departure), Data(price, timeConsuming));
	mTempTimetable.emplace(departure, Data(price, timeConsuming));
}

const double Timetable::getPrice(time_t departure) const {
	auto it = mTimetable.find(departure);
	if (it == mTimetable.end())
		return -1.0;
	return it->second.mPrice;
}

const double Timetable::getTimeConsuming(time_t departure) const {
	auto it = mTimetable.find(departure);
	if (it == mTimetable.end())
		return -1.0;
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
	for (auto pair : mTempTimetable) {
		size_t pos = pair.first.find("+");
		if (pos == std::string::npos) {
			mTimetable.emplace(Backtrack::stringToTime(pair.first+timeZone), Data(pair.second.mPrice, pair.second.mTimeConsuming));
		}
		else {
			mTimetable.emplace(Backtrack::stringToTime(pair.first), Data(pair.second.mPrice, pair.second.mTimeConsuming));
		}
	}
	
}