/*
Question :: check whether a file exists,also checks read,write,execute  permissions of that file..
hint :: man acccess

The access system call determines whether the calling process has access permission to a file."access()" is declared in unistd.h
it can check whether the file exists,and can also verify the read,write,execute permissions.

*/

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char* argv[])
{
char* path = argv[1];
int rval;
/* Check file existence. */
rval = access (path, F_OK);
if (rval == 0)
 printf ("%s exists\n", path);
else {
  if (errno == ENOENT) //error no entry
  printf ("%s does not exist\n", path);
  else if (errno == EACCES) //error not accessible
  printf ("%s is not accessible\n", path);
  return 0;
  }
// Check read access. 
rval = access (path, R_OK);
if (rval == 0)
 printf ("%s is readable\n", path);
else
 printf ("%s is not readable (access denied)\n", path);
// Check write access. 
rval = access (path, W_OK);
if (rval == 0)
 printf ("%s is writable\n", path);
else if (errno == EACCES)
 printf ("%s is not writable (access denied)\n", path);
else if (errno == EROFS) //error read only file system
 printf ("%s is not writable (read-only filesystem)\n", path);
//check whether executable
rval = access (path, X_OK);
if (rval == 0)
  printf ("%s is executable\n", path);
else
 printf ("%s is not executable\n", path);
return 0;
}

