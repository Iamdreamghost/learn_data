#include<stdio.h>

int main()
{
	FILE * src_file,* dst_file;
	char  tmp[10] = {0};
	src_file = fopen("data.txt","r");
	dst_file = fopen("data_copy.txt","w+");
	
	if(src_file == NULL)
	{
		perror("src_file open fail!");
	}
	if(dst_file == NULL)
	{
		perror("dst_file open fail!");
	}
	
	while((fgets(tmp,10,src_file)) != NULL)
	{
		fputs(tmp,dst_file);
	}


	fclose(src_file);
	fclose(dst_file);
	return 0;
}
