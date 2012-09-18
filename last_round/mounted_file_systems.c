/*
Question :: print all mounted file systems 
hint :: <mntent.h> 
        /etc/mtab
        man setmntent

/etc/fstab lists all file systems that can be mounted.Most of the file systems are automatically mounted when the system boots(marked as auto)
 
/etc/mtab lists all file systems that are mounted,it is set by the mount operation.unmount removes this information when file systems are unmounted.
 
(/proc/mounts also lists the file systems mounted with no listing of mount options)

the methods used here are Linux specific.Unix systems have similiar routines,but they are not guarenteed to be identical

structure describing a mount table entry 
 struct mntent
  {
    char *mnt_fsname;		// Device or server for filesystem.
    char *mnt_dir;		// Directory mounted on. 
    char *mnt_type;		// Type of filesystem: ufs, nfs, etc. 
    char *mnt_opts;		// Comma-separated options for fs. 
    int mnt_freq;		// Dump frequency (in days). 
    int mnt_passno;		// Pass number for `fsck'. 
  };

*/

#include<stdio.h>
#include<errno.h>
#include<mntent.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void print_file_system(const struct mntent *fs)
{
 printf("%s %s %s %s %d %d \n",fs->mnt_fsname,fs->mnt_dir,fs->mnt_type,fs->mnt_opts,fs->mnt_freq,fs->mnt_passno);
}


void main(int argc,char *argv[])
{
 char *file="/etc/mtab";
 FILE *ptr;
 errno=0;
 struct mntent *fs;
 ptr=setmntent(file,"r");
 if(ptr==NULL)
  {
   printf("/etc/mtab could not open [%s]\n",strerror(errno));
   exit(EXIT_FAILURE);
  }
 while((fs = getmntent(ptr))!=NULL)
     print_file_system(fs);
 endmntent(ptr);
}
