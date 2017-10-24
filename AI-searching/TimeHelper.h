#pragma once

#ifndef _TIMEHELPER_H
#define _TIMEHELPER_H

#include <string>
#include <time.h>
#include <ctime>
#include <sstream> // std::istringstream

namespace TimeHelper {
    extern std::string timeToString(time_t t, std::string timeZone);
    extern time_t stringToTime(std::string strTime);
    extern bool isWeekend(std::string strDate);
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
    	__unspecified get_time( std::tm* tmb, const CharT* fmt );
    
    	std::istringstream& operator>>( std::istringstream& in, __unspecified un );
    	
    }
    
    errno_t gmtime_s(struct tm *result,const time_t *timep);
	
#endif // __LINUX__


#endif // _TIMEHELPER_H