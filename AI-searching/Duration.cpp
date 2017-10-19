#include "Duration.h"

Duration operator"" _day(unsigned long long x) {
	return Duration((size_t)x * 24ULL * 3600ULL);
}

Duration operator"" _hour(unsigned long long x) {
	return Duration((size_t)x * 3600);
}
Duration operator"" _min(unsigned long long x) {
	return Duration((size_t)x * 60ULL);
}

std::ostream& operator<<(std::ostream& out, const Duration& op) {
	out << op.getSec();
	return out;
}

Duration operator"" _days(unsigned long long x) {
	return Duration((size_t)x * 24ULL * 3600ULL);
}

Duration operator"" _hours(unsigned long long x) {
	return Duration((size_t)x * 3600);
}
Duration operator"" _mins(unsigned long long x) {
	return Duration((size_t)x * 60ULL);
}

Duration operator+(const Duration& a, const Duration& b) {
	return Duration(a.getSec() + b.getSec());
}

Duration& Duration::operator+=(const Duration& x) {
	mDuration += x.mDuration;
	return *this;
}

bool Duration::operator>(const Duration x) const {
	return mDuration > x.mDuration;
}
/*
bool Duration::operator>(const double x) const {
	return mDuration > x;
}
*/
bool Duration::operator<(const Duration x) const {
	return mDuration < x.mDuration;
}
/*
bool Duration::operator<(const double x) const {
	return mDuration < x;
}
*/
bool Duration::operator!=(const Duration x) const {
	return mDuration != x.mDuration;
}
/*
bool Duration::operator!=(const double x) const {
	return mDuration != x;
}
*/

Duration& Duration::operator=(const Duration& x) {
	mDuration = x.mDuration;
	return *this;
}

Duration& Duration::operator=(const time_t x) {
	mDuration = x;
	return *this;
}
