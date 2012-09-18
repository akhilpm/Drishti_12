/*
Question :: Determine the no of processors and no of physical pages on your system
Hint 1.<sys/sysinfo.h>

get_nprocs() - Return number of available processors
get_phys_pages() - Return number of physical pages of memory in the system

*/


#include <stdio.h>
#include <sys/sysinfo.h>

int main ()
{
 printf("no of processors %d  : no of physical pages %ld\n",get_nprocs(),get_phys_pages());
 return 0;
}


