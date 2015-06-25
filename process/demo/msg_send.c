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
	mybuf.mtype = 1;
	strcpy(mybuf.mtext,"hello sundy");
	
	int msgid = msgget(2345,IPC_CREAT|0666);
	if(msgid != -1)
	{
		if(msgsnd(msgid,&mybuf,sizeof(mybuf.mtext),0) != -1)
		{
			printf("send message sucessed\n");
		}else
			perror("msgsend error:");
	}else
		perror("msgget error");
	
	return 0;
}
