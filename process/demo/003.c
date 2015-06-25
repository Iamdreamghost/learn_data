#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
	fork();
	fork();
	fork();
	printf("process id:%d\n",getpid());
	return 1;
}
