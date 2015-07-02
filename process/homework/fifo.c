#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	char buf[100],*fifoname = "tmp";
	
	int fd;
	unlink(fifoname);
	if(mkfifo(fifoname,0666) == -1)
	{
		perror("fifo error:");
		exit(-1);
	}
	while(1)
	{
		fd = open("./tmp",O_RDWR);
		if(fd == -1)
		{
			perror("fd error:");
			exit(-1);
		}
		read(fd,buf,sizeof(buf));
		printf("%s\n",buf);
		close(fd);
	}
	return 0;
}
