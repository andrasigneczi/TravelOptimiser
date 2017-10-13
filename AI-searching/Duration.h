#pragma once

#ifndef _DURATION_H
#define _DURATION_H

#include <iostream>

class Duration {
public:
	Duration(size_t seconds) : mDuration(seconds) {}
    
    double getDay() { return (double)mDuration / 24. * 3600.; }
    double getHour() { return (double)mDuration / 3600.; }
    double getMin() { return (double)mDuration / 60.; }
    size_t getSec() const { return mDuration; }
    
private:
    size_t mDuration; // duration in seconds
};

Duration operator"" _day(unsigned long long x);
Duration operator"" _hour(unsigned long long x);
Duration operator"" _min(unsigned long long x);
std::ostream& operator<<(std::ostream& out, const Duration& op);

Duration operator+(const Duration& a, const Duration& b);
#endif