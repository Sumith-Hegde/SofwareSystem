#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	int linkCreated=symlink("/home/sumithhegde/date.cpp","/home/sumithhegde/dtlink");
	if(linkCreated==0)
	{
		printf("softlink created");
	}
	else
	{
		printf("error!");
	}
	return 0;

}
