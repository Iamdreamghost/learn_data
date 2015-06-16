#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main()
{
	struct stat *file;
	
	int df = stat("/home/blue",file);
	printf("%x\n",file->st_mode);
	return 0;
}
