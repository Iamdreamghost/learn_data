#include<stdio.h>

int main()
{
	FILE * src_file = fopen("data.txt","r");
	FILE * dst_file = fopen("data_copy.txt","w+");
	char tmp;

	if(src_file == NULL)
	{
		perror("Open src_file error");
	}
	if(dst_file == NULL)
	{
		perror("Open dst_file error");
	}
	
	while((tmp = fgetc(src_file)) != EOF)
		fputc(tmp,dst_file);
	
	fclose(src_file);
	fclose(dst_file);
	return 0;
}
