#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	void *share_mem = (void *)0;
	char strbuf[256];
	scanf("%s",strbuf);
	int shmid = shmget(12345,1024,IPC_CREAT|0666);
	if(shmid == -1)
	{
		perror("shmget fail:");
		exit(0);
	}
	share_mem = shmat(shmid,NULL,0);
	if(share_mem == (void *)-1)
	{
		perror("shmat fail:");
		exit(0);
	}
	memcpy(share_mem,strbuf,strlen(strbuf));
	if(shmdt(share_mem) == -1)
	{
		perror("shmdt fail:");
		exit(0);
	}
	return 0;
}
