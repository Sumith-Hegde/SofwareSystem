#include<stdio.h>
#include<unistd.h>
int main()
{
	char buffer[1000];
	int count=0;
	while(1)
	{
		read(0,&buffer[count],1);
		count++;
		if(count==1000||buffer[count-1]=='\n')
		{
			break;
		}
	}
	write(1,&buffer,count);
	return 0;
}
