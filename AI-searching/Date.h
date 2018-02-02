#pragma once

#ifndef _DATE_H
#define _DATE_H

#include <string>

class Date {
public:
    Date();
    
    Date& operator=( const std::string& value );
    Date& operator=( const Date& value );
    
    bool operator<( const Date& value );
    bool operator>( const Date& value );
    Date& operator++();
    
    bool isNull() const { return mNull; }
    
private:
    int mYear;
    int mMonth;
    int mDay;
    int mWDay;
    
    bool mNull;
};

#endif
