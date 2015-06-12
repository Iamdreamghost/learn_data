#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int in,out;
	char c;
	//oprn
	in = open("file.in",O_RDONLY,0666);
	out = open("file.out",O_RDWR|O_CREAT,0666);
	if(in == -1)
	{
		printf("Read error!\n");
		exit(-1);
	}
	if(out == -1)
	{
		printf("Write error!\n");
		exit(-1);
	}
	//read
	while(read(in,&c,1))
	//write
		write(out,&c,1);
	//close
	close(in);
	close(out);
	
}
