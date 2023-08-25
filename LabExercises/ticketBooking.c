#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd=open("/home/sumithhegde/ticket",O_EXCL|O_RDWR);
	//printf("%d\n",fd);
	struct flock lock;
	lock.l_type=F_WRLCK;
	lock.l_whence=SEEK_SET;
	lock.l_start=0;
	lock.l_len=2;
	lock.l_pid=getpid();
	int l=fcntl(fd,F_SETLKW,&lock);
	//printf("%d\n",l);
	char buff[3]={'0','0','\0'};
	read(fd,buff,2);
	int available=(buff[0]-'0')*10+(buff[1]-'0');
	//printf("available - %d\n",available);
	if(available>0)
	{
		printf("press enter to confirm\n");
		getchar();
		available--;
		//printf("%d\n",available);
		//printf("%d\n",available/10);
		//printf("%d\n",available%10);
		buff[0]='0'+(available/10);
		buff[1]='0'+(available%10);
		//printf("%d\n",buff[0]-'0');
		//printf("%d\n",buff[1]-'0');
		//printf("%ld\n",lseek(fd,0,SEEK_SET));
		write(fd,buff,2);
		lock.l_type=F_UNLCK;
		fcntl(fd,F_SETLKW,&lock);
		printf("Ticket number %d booked\n",available+1);
	}
	else
	{
		printf("tickets not available\n");
	}
	return 0;
}

