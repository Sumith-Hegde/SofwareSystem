#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	fd_set readfds;
        struct timeval T;
        int sReturn=0;
	FD_ZERO(&readfds);
        FD_SET(0,&readfds);
        T.tv_sec=10;
        T.tv_usec=0;
        sReturn=select(1,&readfds,NULL,NULL,&T);
        if(sReturn==-1)
	{
		perror("select:");
	}
        else if(sReturn)
	{
		printf("data recieved within 10 seconds\n");
	
	}
        else
	{
		printf("data was not recieved\n");
	}
	fflush(stdin);	
	return 0;
}

         

