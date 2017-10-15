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
