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
	
	char buf[1024];
	memset(buf,0,1024);
	int count = lseek(fd,0,SEEK_END);
	int size = read(fd,buf,1024);
	if(size == -1)
	{
		printf("Read error!\n");
		exit(-1);
	}
	printf("%d\n",count);
	close(fd);
	printf("close\n");
	return 0;
}
