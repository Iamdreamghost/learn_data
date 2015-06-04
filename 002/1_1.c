//写一个函数，求一个字符串的长度
#include<stdio.h>

int str_len(const char *p);
int main()
{
	printf("%d\n",str_len("ssssffff"));
	return 0;
}

int str_len(const char *pstr)
{
	int i = 0;
	while(*pstr++!='\0')
	{
		i++;
	}	
	return i;
}
