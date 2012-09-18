/*
Question :: Get current resource limits of the running program(max cpu time,max data segment size,max no of child processes possible for the running
            program,max no of files possible to open at a time).
            Set new values for the resource limits as
            MAX CPU TIME = 1 sec
            MAX DATA MEMORY SIZE = 1024 bytes
            MAX NO OF CHILD PROCESSES = 1000
            MAX NO OF FILES POSSIBLE TO OPEN AT A TIME = 100 

hint :: man getrlimit
        man setrlimit
        header <sys/resource.h>        

For each resource there are two limits, the hard limit and the soft limit.The soft limit may never exceed the hard limit, and only processes with superuser privilege may change the hard limit.

The getrlimit and setrlimit system calls allow a process to read and set limits on the system resources that it can consume.

some possible resources to set custom limits are

  RLIMIT_CPU—The maximum CPU time, in seconds, used by a program.

  RLIMIT_DATA—The maximum amount of memory that a program can allocate for its data.

  RLIMIT_NPROC—The maximum number of child processes that can be running for this user.

  RLIMIT_NOFILE—The maximum number of file descriptors that the process may have open at one time.



struct rlimit {
    rlim_t rlim_cur;   // Soft limit
    rlim_t rlim_max;   // Hard limit 
};

*/

#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include<stdio.h>

int main ()
{
struct rlimit rl;
// Obtain the current limits. 
//1.max cpu time
getrlimit (RLIMIT_CPU, &rl); 
printf("MAX CPU TIME %lld SECONDS \n\n",(long long int)rl.rlim_cur);
//2.max size of data segment 
getrlimit (RLIMIT_DATA, &rl);
printf("MAX DATA MEMORY %lld \n BYTES \n\n",(long long int)rl.rlim_cur);
//3.max no of child processes possible
getrlimit (RLIMIT_NPROC, &rl);
printf("MAX NO OF CHILD PROCESSES %ld \n\n",(long int)rl.rlim_cur);
//4.max no of files possible to open at a time
getrlimit (RLIMIT_NOFILE, &rl);
printf("MAX NO OF FILES OPEN AT A TIME %ld \n\n",(long int)rl.rlim_cur);

//set new resource limits
// Set a CPU limit of 1 second.
getrlimit (RLIMIT_CPU, &rl); 
rl.rlim_cur = 1;
setrlimit (RLIMIT_CPU, &rl);
printf("NEW CPU TIME %lld SECONDS \n\n",(long long int)rl.rlim_cur);
//Set a data segment size of 1 KB
getrlimit (RLIMIT_DATA, &rl); 
rl.rlim_cur = 1024;
setrlimit (RLIMIT_DATA, &rl);
printf("NEW DATA MEMORY SIZE %lld BYTES \n\n",(long long int)rl.rlim_cur);
//Set no of child processes to 1000
getrlimit (RLIMIT_NPROC, &rl); 
rl.rlim_cur = 1000;
setrlimit (RLIMIT_NPROC, &rl);
printf("NEW NO OF CHILD PROCESSES %ld \n\n",(long int)rl.rlim_cur);
//Set max no of file descriptors to 1000
getrlimit (RLIMIT_NOFILE, &rl); 
rl.rlim_cur = 100;
setrlimit (RLIMIT_NOFILE, &rl);
printf("NEW NO OF FILES OPEN AT A TIME %ld \n\n",(long int)rl.rlim_cur);

// Do busy work. 
while (1);
return 0;
}

