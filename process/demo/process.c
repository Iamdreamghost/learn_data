#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<time.h>
#include<sys/stat.h>
#include<stdlib.h>

int main()
{
	pid_t pid = fork();
	int i;
	FILE * fp;
	time_t t;
	
	if(pid < 0)
	{
		perror("pid fail");
		exit(1);
	}else if(pid > 0)
	{
		exit(0);
	}else if(pid == 0)
	{
		setsid();
		chdir("/home/blue/");
		umask(0);
		for(i=0; i<10240; ++i)
		{
			close(i);
		}
	}
	
	while(1)
	{
		sleep(3);
		if((fp=fopen("log.txt","a+")) >= 0)
		t = time(0);
		fprintf(fp,"%s",asctime(localtime(&t)));
		fclose(fp);
	}	
	
	return 1;
}
