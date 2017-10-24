#include "TimeHelper.h"
#include <ctime>
#include <iomanip>      // std::get_time
#include <string.h>
#include <iostream>

#ifdef __LINUX__

namespace std {
	
	std::string put_time( struct tm* tm, const char* format ) {
		char foo[124];
	
		if(0 < strftime(foo, sizeof(foo), format, tm))
			return std::string( foo );
		std::cerr << "Something went wrong1\n";
		return std::string();
	}
	
	template< class CharT >
	__unspecified get_time( std::tm* tmb, const CharT* fmt ) {
          __unspecified ret;
          ret.fmt = fmt;
          ret.tmb = tmb;
          return ret;
	}
	
	std::istringstream& operator>>( std::istringstream& in, __unspecified un ) {
		char buff[256];
		in.getline(buff, 256);
		
          if(strptime(buff, un.fmt, un.tmb) == NULL) {
          	std::cerr << "Something went wrong2: " << buff << " " << un.fmt << std::endl;
          }
		
		//std::cerr << v << std::endl;
		return in;
	}
	
}

	errno_t gmtime_s(struct tm *result,const time_t *timep) {
		if( gmtime_r(timep, result) != nullptr )
			return 0;
		return 1;
	}
#endif

namespace TimeHelper {
std::string timeToString(time_t t, std::string timeZone) {
	struct tm tm;
	memset(&tm, 0, sizeof(tm));

	size_t pos = timeZone.find("+");
	int tmz = 0;
	if (pos != std::string::npos) {
		tmz = ((timeZone[pos + 1] - '0') * 10 + (timeZone[pos + 2] - '0')) * 3600;
		tmz += ((timeZone[pos + 3] - '0') * 10 + (timeZone[pos + 4] - '0')) * 60;
	}
	else {
		tmz = 2 * 3600;
	}

	t += tmz;
	/*errno_t err = */gmtime_s(&tm, &t);
	//errno_t err = localtime_s(&tm, &t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d %R");
	oss << timeZone;
	return oss.str();
}

time_t stringToTime(std::string strTime) {
	struct std::tm tm;
	memset(&tm, 0, sizeof(tm));
	//std::string strTime("2017-08-12 11:50+0300");
	std::istringstream ss(strTime);
	ss >> std::get_time(&tm, "%Y-%m-%d %R");
	size_t pos = strTime.find("+");
	int tmz = 0;
	if (pos != std::string::npos) {
		tmz = (strTime[pos + 1] - '0') * 10 + (strTime[pos + 2] - '0');
	}
	else {
		tmz = 2;
	}
	time_t t = mktime(&tm);
	t -= (tmz - 1) * 60 * 60;
	//timeToString(t);
	return t;
}
}
