#include<stdio.h>

int stream_attribute(FILE * fp)
{
	if(fp->_flags & _IO_UNBUFFERED)
	{
		printf("The IO type is unbuffered.\n");
	}else if(fp->_flags & _IO_LINE_BUF)
	{
		printf("The IO type is line buf\n");
	}else
	{
		printf("The IO type is full buf\n");
	}
	printf("The IO size : %d\n",fp->_IO_buf_end-fp->_IO_buf_base);
	return 0;
}

int main()
{
	FILE *fp;
	getchar();
	stream_attribute(stdin);
	printf("_________________________________\n\n");
	stream_attribute(stdout);
	printf("_________________________________\n\n");
	stream_attribute(stderr);
	if((fp = fopen("test.txt","w+")) == NULL)
	{
		perror("fail to open");
	}
	printf("_________________________________\n\n");
	fputc('a',fp);
	stream_attribute(fp);
	return 0;
}
