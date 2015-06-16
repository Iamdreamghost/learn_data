#include<stdio.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
	FILE * file;
	char tmp;
	int i=0;
	
	if(argc == 1)
	{
		printf("input file\n");
		exit(1);
	}
	
	file = fopen(argv[1],"r");
	if(file == NULL)
	{
		perror("open fail!");
		exit(1);
	}
	
	while(fread(&tmp,1,1,file))
	{
		if(tmp == '\n')
			i++;
	}
	
	printf("%d\n",i);	

	fclose(file);
	return 0;
}
