#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

void ls(char * pathfile)
{
	DIR * dirname = NULL;
	struct dirent * sfile;

	dirname = opendir(pathfile);
	
	while(sfile = readdir(dirname))
	{
		if(strcmp(sfile->d_name,".")==0||strcmp(sfile->d_name,"..")==0)
			continue;
		printf("%s\n",sfile->d_name);
	}
	closedir(dirname);
}

int main(int argc,char * argv[])
{
	if(argc == 1)
	{
		printf("Input file\n");
		exit(1);
	}else
	{
		ls(argv[1]);
	}

	return 1;
}
