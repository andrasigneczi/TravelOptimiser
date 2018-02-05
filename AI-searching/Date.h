#pragma once

#ifndef _DATE_H
#define _DATE_H

#include <string>

class Date {
public:
    Date();
    explicit Date( const std::string& value );
    Date& operator=( const std::string& value );
    Date& operator=( const Date& value );
    bool operator==( const Date& value ) const;
    
    bool operator<( const Date& value ) const;
    bool operator>( const Date& value ) const;
    Date& operator++();
    
    bool isNull() const { return mNull; }
    
    int getDay()   const { return mDay;   }
    int getWDay()  const { return mWDay;  }
    int getMonth() const { return mMonth; }
    int getYear()  const { return mYear;  }
    
private:
    int mYear;
    int mMonth;
    int mDay;
    int mWDay; // Sunday = 0, Monday = 1, ...
    
    bool mNull;
};

#endif
