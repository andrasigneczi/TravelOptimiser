#include <ctime>
#include <iomanip>      // std::get_time
#include <string.h>
#include <iostream>
#include <sstream> // std::istringstream

#include "Date.h"
#include "TimeHelper.h"

Date::Date() {
    mYear  = 0;
    mMonth = 0;
    mDay   = 0;
    mWDay  = 0;
    mNull  = true;
}

Date& Date::operator=( const std::string& value ) {
	struct std::tm tm;
	memset(&tm, 0, sizeof(tm));
	//std::string strTime("2017-08-12 11:50+0300");
	std::istringstream ss(value);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	
	mYear  = tm.tm_year + 1900;
	mMonth = tm.tm_mon + 1;
	mDay   = tm.tm_mday;
	mWDay  = tm.tm_wday + 1;
	mNull  = false;
}

Date& Date::operator=( const Date& value ) {
    if( &value != this ) {
        mYear  = value.mYear ;
        mMonth = value.mMonth;
        mDay   = value.mDay  ;
        mWDay  = value.mWDay ;
        mNull  = value.mNull ;
    }
    return *this;
}

bool Date::operator<( const Date& value ) {
    if( isNull() || value.isNull())
        return false;
    
    if( mYear < value.mYear ) return true;
    if( mYear > value.mYear ) return false;
    
    if( mMonth < value.mMonth ) return true;
    if( mMonth > value.mMonth ) return false;

    if( mDay < value.mDay ) return true;
    if( mDay > value.mDay ) return false;
    
    return true;
}

bool Date::operator>( const Date& value ) {
    if( isNull() || value.isNull())
        return false;
    
    if( mYear > value.mYear ) return true;
    if( mYear < value.mYear ) return false;
    
    if( mMonth > value.mMonth ) return true;
    if( mMonth < value.mMonth ) return false;

    if( mDay > value.mDay ) return true;
    if( mDay < value.mDay ) return false;
    
    return true;
}

Date& Date::operator++() {
    static const int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    
    if( isNull())
        return *this;
    
    int leap = 0;
    if( TimeHelper::isLeapYear( mYear ) && mMonth == 2 )
        leap = 1;
        
    if( monthDays[mMonth-1] + leap == mDay ) {
        if( mMonth == 12 ) {
            ++mYear;
            mMonth = 1;
            mDay = 1;
        } else {
            
        }
    } else {
        ++mDay;
    }
    return *this;
}
