#pragma once

#ifndef _DURATION_H
#define _DURATION_H

#include <iostream>

class Duration {
public:
    Duration() : mDuration(0) {}
	explicit Duration(time_t seconds) : mDuration(seconds) {}
    
    double getDay() const { return (double)mDuration / 24. / 3600.; }
    double getHour() const { return (double)mDuration / 3600.; }
    double getMin() const { return (double)mDuration / 60.; }
    time_t getSec() const { return mDuration; }

    Duration& operator+=(const Duration& x);
    Duration& operator=(const Duration& x);
    Duration& operator=(const time_t x);
    bool operator>(const Duration x) const;
    //bool operator>(const double x) const;    
    bool operator<(const Duration x) const;
    //bool operator<(const double x) const;    
    bool operator!=(const Duration x) const;
    //bool operator!=(const double x) const;    
private:
    time_t mDuration; // duration in seconds
};

Duration operator"" _day(unsigned long long x);
Duration operator"" _hour(unsigned long long x);
Duration operator"" _min(unsigned long long x);
Duration operator"" _days(unsigned long long x);
Duration operator"" _hours(unsigned long long x);
Duration operator"" _mins(unsigned long long x);
std::ostream& operator<<(std::ostream& out, const Duration& op);

Duration operator+(const Duration& a, const Duration& b);

#endif