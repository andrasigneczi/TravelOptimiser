#include "Timetable.h"
#include "Backtrack.h"
#include <assert.h>

void Timetable::add(std::string departure, double price, Duration timeConsuming) {
	//mTimetable.emplace(Backtrack::stringToTime(departure), Data(price, timeConsuming));
	mTempTimetable.emplace(departure, Data(price, timeConsuming.getSec()));
}

const double Timetable::getPrice(time_t departure) const {
	auto it = mTimetable.find(departure);
	if (it == mTimetable.end())
		return -1.0;
	return it->second.mPrice;
}

const time_t Timetable::getTimeConsuming(time_t departure) const {
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
