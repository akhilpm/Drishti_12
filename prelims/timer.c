/*
QUESTION : write a program to count numbers for 2 seconds with a timer(real timer)

hint = man setitimer

struct itimerval{
    struct timeval it_interval; // next value 
    struct timeval it_value;    // current value 
    };

struct timeval it_value-> contains the time until the timer next expires and a signal is sent. If this is 0, the timer is disabled.
struct timeval it_interval-> contains the value to which the timer will be reset after it expires. If this is 0, the timer will be disabled after it
                             expires. If this is nonzero, the timer is set to expire repeatedly after this interval.


*/

#include<stdio.h>
#include<sys/time.h>


int main ()
{
struct itimerval timer;
int ret,i=0;
// Configure the timer to expire after 2 sec... 
timer.it_value.tv_sec = 2;
timer.it_value.tv_usec = 000000;
// ... after expiry disable the timer by reseting the interval to zero
timer.it_interval.tv_sec = 0;
timer.it_interval.tv_usec = 000000;
// Start a real timer. It counts down whenever this process is executing.
ret=setitimer (ITIMER_REAL, &timer, NULL);
// Do busy work.
while (1)
 {
 printf("\n%d\n",i++);
 }
}
