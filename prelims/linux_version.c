/*
Question :: Print system information.A custom implementation of "uname -a" command
hint 1.<sys/utsname.h>

struct utsname
  {
    // Name of the implementation of the operating system.  
    char sysname[_UTSNAME_SYSNAME_LENGTH];

    // Name of this node on the network.  
    char nodename[_UTSNAME_NODENAME_LENGTH];

    // Current release level of this implementation. 
    char release[_UTSNAME_RELEASE_LENGTH];
    // Current version level of this release.  
    char version[_UTSNAME_VERSION_LENGTH];

    // Name of the hardware type the system is running on.
    char machine[_UTSNAME_MACHINE_LENGTH];

#if _UTSNAME_DOMAIN_LENGTH - 0
    // Name of the domain of this node on the network. 
# ifdef __USE_GNU
    char domainname[_UTSNAME_DOMAIN_LENGTH];
# else
    char __domainname[_UTSNAME_DOMAIN_LENGTH];
# endif
#endif
 };

*/

#include <stdio.h>
#include <sys/utsname.h>
int main ()
{
struct utsname u;
uname (&u);
printf ("%s %s %s %s %s %s\n", u.sysname, u.nodename,u.release,u.version, u.machine,u.__domainname);
return 0;
}

