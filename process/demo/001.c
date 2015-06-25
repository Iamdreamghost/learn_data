#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
	pid_t pid = fork();
	if(pid<0)
	{
		printf("fail\n");
		exit(1);
	}else if(pid > 0)
	{
		printf("这是父进程:%d\n",getpid());
		
	}else
	{
		printf("这是子进程%d\n",getppid());
	}
	
	return 0;
}
