#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char * argv[])
{
	int fd;
	
	if(argc == 1)
	{
		printf("input file\n");
		exit(1);
	}
	
	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		perror("open fail!");
		exit(1);
	}
	
	close(fd);
	return 0;
}
