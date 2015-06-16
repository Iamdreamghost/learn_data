#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int src_file , dst_file;
	char tmp;
	
	src_file = open("data.txt",O_RDONLY,0444);
	dst_file = open("data_copy.txt",O_RDWR|O_CREAT,0666);
	if(src_file == -1)
	{
		perror("Open src_file fail!");
		exit(1);
	}
	if(dst_file == -1)
	{
		perror("Open dst_file fail!");
		exit(1);
	}
	
	
	while(read(src_file,&tmp,1))
			write(dst_file,&tmp,1);
	
	close(src_file);
	close(dst_file);
	return 0;
}
