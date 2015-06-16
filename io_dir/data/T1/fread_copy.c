#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE * src_file = fopen("data.txt","r");
	FILE * dst_file = fopen("data_copy.txt","w+");
	char tmp[100] = {0};	

	if(src_file == NULL)
	{
		perror("open src_file fail!");
		exit(-1);
	}
	if(dst_file == NULL)
	{
		perror("open dst_file fail!");
		exit(-1);
	}
	
	while(fread(tmp,100,1,src_file)>0)
		fwrite(tmp,100,1,dst_file);
	
	fclose(src_file);
	fclose(dst_file);
}
