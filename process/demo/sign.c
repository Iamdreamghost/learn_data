#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>

int main(int argc,char *argv[])
{
	pid_t pid;
	int ret;
	pid = fork();
	if(pid < 0)
	{
		perror("fork \n");
		exit(1);
	}else if(pid == 0)
	{
		printf("in child\n");
		if(raise(SIGSTOP) == -1)
			perror("raise");
	}else
	{
		printf("now in parent\n");
		if(waitpid(pid,NULL,WNOHANG) == 0)
		{
			printf("send kill to child\n");
			if(kill(pid,SIGKILL) == -1)
			{
				perror("kill");
				exit(1);
			}else
			{
				printf("send kill success\n");
			}
		}	
	}

	return 0;
}
