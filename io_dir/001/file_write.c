#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{

	int fd = open("hello",O_RDWR|O_CREAT,0666);
	if(fd == -1)
	{
		printf("error\n");
		exit(-1);
	}
	
	char buf[] = "Hello Yulong";
	int retunum = write(fd,buf,strlen(buf));
	if(retunum == -1)
	{
		printf("write error!\n");
		exit(-1);
	}
	close(fd);
	printf("close\n");
	return 0;
}
