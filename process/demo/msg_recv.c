#include<stdio.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>

struct msgbuf
{
	long mtype;
	char mtext[255];
};

int main()
{
	struct msgbuf mybuf;
	//mybuf.mtype = 1;
	//strcpy(mybuf.mtext,"hello sundy");
	
	int msgid = msgget(2345,IPC_CREAT|0666);
	if(msgid != -1)
	{
		if(msgrcv(msgid,&mybuf,sizeof(mybuf.mtext),0,IPC_NOWAIT) != -1)
		{
			printf("recvive message %s\n",mybuf.mtext);
			if(msgctl(msgid,IPC_RMID,0) != -1)
					printf("delect success!\n");
			else
					perror("delect fail:");
		}else
			perror("msgrecv error:");
	}else
		perror("msgget error");
	
	return 0;
}
