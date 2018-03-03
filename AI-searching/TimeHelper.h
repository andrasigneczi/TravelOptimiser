#pragma once

#ifndef _TIMEHELPER_H
#define _TIMEHELPER_H

#include <string>
#include <time.h>
#include <ctime>
#include <sstream> // std::istringstream

namespace TimeHelper {
    extern std::string timeToString(time_t t, std::string timeZone);
    extern time_t stringToTime(std::string strTime); // "2017-08-12 11:50+0300", "2017-08-12 11:50"
    extern bool isWeekend(std::string strDate);
    extern int getWeekday(std::string strDate);
    extern bool isLeapYear( int year );
    
    // output parameters: hour, min
    extern void parseStringTime( std::string time, int& hour, int& min ); // "X 1:10", "A 21:23", "1:05", "13:04"
}

#ifdef __LINUX__
    typedef int errno_t;
    
    namespace std {
    	
		struct __unspecified { 
			operator char*() {
				return nullptr;
			}
			
			operator bool&() {
				return b;
			}
			
			bool b;
			std::tm* tmb;
			const char* fmt;
		};
    	
    	std::string put_time( struct tm* tm, const char* format );
    	
		template< class CharT >
		__unspecified get_time( std::tm* tmb, const CharT* fmt ) {
	          __unspecified ret;
	          ret.fmt = fmt;
	          ret.tmb = tmb;
	          return ret;
		}
    
    	std::istringstream& operator>>( std::istringstream& in, __unspecified un );
    	
    } // std
    
    errno_t gmtime_s(struct tm *result,const time_t *timep);
	
#endif // __LINUX__


#endif // _TIMEHELPER_H