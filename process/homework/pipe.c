#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

int main()
{
	pid_t pid1,pid2;
	int pd[2];
	char * w_str = "beautiful girl";
	char r_str[30];
	
	if(pipe(pd) == 0)
	{
		pid1 = fork();
		if(pid1 == -1)
		{
			perror("fork fail");
			exit(0);
		}
	}

	if(pid1 > 0)
	{
		wait(NULL);
		close(pd[1]);
		read(pd[0],r_str,sizeof(r_str));
		printf("%s\n",r_str);

		pid2 = fork();
	 	if(pid2 == 0)
		{
			w_str = "Child process is 2";
			close(pd[0]);
			if(write(pd[1],w_str,strlen(w_str)) == -1)
				perror("write fail");
		}
		/*else if(pid2 > 0)
		{
			close(pd[1]);
			read(pd[0],r_str,sizeof(r_str));
			printf("%s\n",r_str);
			
		}*/
	}else if(pid1 == 0)
	{
		w_str = "Child process is 1";
		close(pd[0]);
		write(pd[1],w_str,strlen(w_str));
	}
	
	return 0;
}
