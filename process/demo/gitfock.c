#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid == -1)
		perror("Fail!");
	else if(pid == 0)
		printf("%d\n",getpid());
	else
		printf("%d\n",getppid());
	return 0;
}
