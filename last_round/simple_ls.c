/*
Question :: implement a simple "ls" program(only list a specified directory contents)

hint 1.man opendir
     2.header <dirent.h>

A directory is a special kind of file,which associates filenames with  particular collections of file metadata known as inodes
inode is the short of index-node.

directory entries are represented as
 struct	dirent{ 
   long d_ino; //inode no which is unique for a file
   off_t d_off; 
   unsigned short d_reclen; 
   char d_name[1]; 
};

The field d_ino is a number which is unique for each file in the file system. The field d_off represents an offset of that directory entry in the actual file system directory. The field d_name is the beginning of the character array giving the name of the directory entry. This name is null terminated and may have at most NAME_MAX characters in addition to the null terminator. This results in file system independent directory entries being variable-length entities. The value of d_reclen is the record length of this entry. 

NAME_MAX is defined in limits.h(its value is 255)

DIR type is analogous to FILE type in stdio.h.readdir() returns NULL upon end of file.

*/

#include<stdio.h>
#include<errno.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

int process(char dir[])
{
 DIR *dp;
 struct dirent *entry;
 errno=0;
 if((dp=opendir(dir))==NULL)
  {
   printf("\ndirectory cannot open for reading [%s]\n",strerror(errno));
   return 1;
  }
 errno=0;
 while((entry=readdir(dp))!=NULL)
   printf("\n%s",entry->d_name);
 printf("\n");
 if(errno!=0)
   {
    printf("\nError while reading directory entries [%s]\n",strerror(errno));
    return 1;
   }
 if(closedir(dp)!=0)
   {
    printf("Error while closing directory [%s]\n",strerror(errno));
    return 1;
   }
 return 0;
}

void main(int argc,char *argv[])
{
 int error;
 if(argc==1)
    error=process(".");
 else
    error=process(argv[1]);
 if(error==1)
    printf("\nError while processing\n!!!");
}

