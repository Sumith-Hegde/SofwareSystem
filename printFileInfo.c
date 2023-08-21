#include<stdio.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(int argc,char * argv[])
{
	if(argc!=2)
	{
		printf("file not specified\n");
		return 0;
	}
	struct stat fileInfo;
	int status=stat(argv[1],&fileInfo);
	if(status==-1)
	{
		printf("failed to get the file\n");
	}
	else
	{
		printf("inode number - %ld\n",fileInfo.st_ino);
		printf("mode - %ld\n",fileInfo.st_mode);
		printf("number of hardlinks - %ld\n",fieInfo.st_nlink);
		printf("user id - %ld\n",fileInfo.st_uid);
		printf("group id - %ld\n",fileInfo.st_gid);
		printf("size - %ld\n",fileInfo.st_size);
		printf("block size - %ld\n",fileInfo.st_blksize);
	}
	return 0;
}
