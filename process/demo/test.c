#include<stdio.h>
#include<sys/types.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
	int i = 0;
	if(fork() == 0)
		i++;
	if(fork() == 0)
		i++;
	if(fork() == 0)
		i++;
	if(fork() == 0)
		i++;
	printf("%d\n",i);
	return 0;
}
