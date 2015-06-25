#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdio.h>

int main()
{
	char contents[] = "hello matix";
	void * share_mem = (void *)0;
	
	int shmid = shmget(2345,2048,IPC_CREAT|0666);
	if(shmid != -1)
	{
		share_mem = shmat(shmid,NULL,0);
		if(share_mem != (void *)-1)
		{
			printf("this share_memary:%s\n",(char *)share_mem);
			shmdt(share_mem);
		}
	}
	return 0;
}
