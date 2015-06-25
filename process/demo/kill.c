#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>

int main()
{
	kill(3040,SIGKILL);
	return 0;
}
