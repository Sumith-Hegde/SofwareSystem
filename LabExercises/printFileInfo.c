#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
int main(int argc,char* argv[])
{
	if(argc!=2)
	{
		printf("please provide input file name properly\n");
		return 0;
	}
	struct stat fileInfo;
	int success=stat(argv[1],&fileInfo);
	if(success==-1)
	{
		printf("failed to get info\n");
		return 0;
	}
	printf("file info :\n");
    	printf("inode number : %lu\n", fileInfo.st_ino);
    	printf("hard links : %lu\n", fileInfo.st_nlink);
    	printf("user ID : %u\n", fileInfo.st_uid);
    	printf("group ID : %u\n", fileInfo.st_gid);
    	printf("size : %ld bytes\n", fileInfo.st_size);
    	printf("block size : %ld bytes\n", fileInfo.st_blksize);

    	printf("last access: %s", ctime(&fileInfo.st_atime));
    	printf("last modification: %s", ctime(&fileInfo.st_mtime));
   	printf("last change: %s", ctime(&fileInfo.st_ctime));
	return 0;
}
