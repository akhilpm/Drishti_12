/*
Question :: Implementation of mkdir and rmdir commands
hint :: 1.<sys/types.h>
        2.<unistd.h>


Directory must be empty before removing it.If a directory is not empty errno is set to ENOTEMPTY while executing rmdir. 
New directories,like all files are assigned a group ID number. 

for mkdir() the mode argument represents the permissions to be applied to that directory.It is exactly analogous to  the permisssions of a file
(read,write & execute permissions for owner,group & other).

*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

void create_directory(char path[])
{
 int retcode;
 errno=0;
 retcode=mkdir(path,0755); // declared in sys/stat.h
 printf("make directory %s :: status [%s]",path,strerror(errno));
}

void delete_directory(char path[])
{
 int retcode;
 errno=0;
 retcode=rmdir(path); // declared in unistd.h
 printf("remove directory %s :: status [%s]",path,strerror(errno));
}

void main(int argc,char *argv[])
{
 int choice;
 printf("\n enter choice");
 printf("\n1.create directory \n2.remove directory \n");
 scanf("%d",&choice);
 if(choice==1)
  create_directory(argv[1]);
 else if(choice==2)
  delete_directory(argv[1]);
 else
  printf("\nerror..invalid choice\n");
}

