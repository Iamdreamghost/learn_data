#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>

int main(void)
{
	int result = -1;
	int fd[2],nbytes;
	pid_t pid;
	char string[]="hell world,my pipe!";
	char readbuffer[100];

	int *write_fd=&fd[1];
	int *read_fd=&fd[0];

	result = pipe(fd);
	if(-1 == result)
	{
		printf("fail to create pipe\n");
		return -1;
	}
	
	pid = fork();

	if(-1 == pid)
	{
		printf("fail to fork\n");
		return -1;
	}else if(0 == pid)
	{
		close(*read_fd);
		result = write(*write_fd,string,strlen(string));
		return 0;
	}else
	{
		close(*write_fd);
		nbytes = read(*read_fd,readbuffer,sizeof(readbuffer));
		printf("the parent receive %d bytes data %s \n",nbytes,readbuffer);
	}
	
	return 0;
}
