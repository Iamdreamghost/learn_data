#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char str[] = "this is a process!\n";
	char buf[20];

	mkfifo("tmp",0666);
	pid_t pid = fork();

	if(pid < 0)
		exit(1);
	else if(pid>0)
	{
		FILE * fifo = fopen("tmp","w");
		fwrite(str,strlen(str),1,fifo);
		fclose(fifo);
	}else
	{
		FILE * fifo = fopen("tmp","r");
		fread(buf,sizeof(buf),1,fifo);
		printf("%s",buf);
		fclose(fifo);
	}
	return 0;
}
