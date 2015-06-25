#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdio.h>

int semid;
struct sembuf sem_down = {1,-1,0} ;
struct sembuf sem_up = {0,1,0};

void down()
{
	semop(semid,&sem_down,1);
}

void up()
{
	semop(semid,&sem_up,1);
}

int main()
{
	//1.create sem
	semid = semget(2345,1,IPC_CREAT|0666);
	if(semid != -1)
	{
		//2.set semaphore = 1
		semctl(semid,1,SETVAL);
		//3.lock unlock
		down();
		printf("Hello world!\n");
		sleep(10);
		up();

	}else
		perror("Sem create fail:");
	
	return 0;
}
