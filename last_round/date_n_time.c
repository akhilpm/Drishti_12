/*
Question:: get system time and convert it into local time(Print date and time)

hint 1.man gettimeofday
     2.<time.h>

.time is expressed as no of seconds from 1970 jan 1 midnight to a variable time_t.In 2038 the 32 bit machines will reset the time again to 1970   since the count will exceed 2^32.making time_t unsigned will merely postpone the problem to 2106.:) (2038 problem)


struct timeval - This structure represents a time, in seconds, split into two fields.The tv_sec field contains the integral number of seconds, and the tv_usec field contains an additional number of microseconds

struct tm
{
  int tm_sec;			// Seconds.	[0-60] (1 leap second) 
  int tm_min;			// Minutes.	[0-59] 
  int tm_hour;			// Hours.	[0-23] 
  int tm_mday;			// Day.		[1-31] 
  int tm_mon;			// Month.	[0-11] 
  int tm_year;			// Year	- 1900.  
  int tm_wday;			// Day of week.	[0-6] 
  int tm_yday;			// Days in year.[0-365]	
  int tm_isdst;			// DST.		[-1/0/1]

#ifdef	__USE_BSD
  long int tm_gmtoff;		// Seconds east of UTC.  
  __const char *tm_zone;	// Timezone abbreviation.  
#else
  long int __tm_gmtoff;		// Seconds east of UTC.  
  __const char *__tm_zone;	// Timezone abbreviation.  
#endif
};

*/

#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void main()
{
struct timeval tv;
struct tm* ptm;
char time_string[40];
long milliseconds;
/* Obtain the time of day, and convert it to a tm struct.tm struct is declared in time.h */
gettimeofday (&tv, NULL); //in sys/time.h
ptm = localtime (&tv.tv_sec); //in time.h
/* Format the date and time. the format character specifications are available in the man page of strftime. */
strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm); //in time.h
/* Compute milliseconds from microseconds. */
milliseconds = tv.tv_usec / 1000;
/* Print the formatted time, in seconds and the milliseconds. */
printf ("%s.%03ld\n", time_string, milliseconds);
}

