#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
	int fileDesc=creat("/home/sumithhegde/newFile",S_IRWXU);
	printf("%d\n",fileDesc);
	return 0;
}
