#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

void demon_init()
{
	int i;
	pid_t pid;
	pid = fork();
	if(pid < 0) exit(1);
  if(pid > 0) exit(1);

	if(setsid() < 0) exit(1);
	
	pid = fork();
	if(pid < 0) exit(1);
  if(pid > 0) exit(1);
	
	for(i=0;i<10240;i++)
		close(i);
}

int main()
{
	char str[] = "this is a text!\n";
	demon_init();
	while(1)
	{
		FILE * fdata = fopen("text.txt","a+");
		fwrite(str,strlen(str),1,fdata);
		fclose(fdata);
		sleep(5);
	}
	return 0;
}
