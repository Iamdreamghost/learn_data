//实现删除字符串中空格的功能
#include<stdio.h>

void my_swap(char * Pstr);
int main()
{
	char str[] = "H e l l o w o r l d!";
	printf("%s\n",str);
	my_swap(str);
	printf("%s\n",str);
	return 0;
}

void my_swap(char * Pstr)
{
	char *Ptmp = Pstr;
	
	while(*Pstr != '\0')
	{
		if(*Pstr != ' ')
		{
			*Ptmp++ = *Pstr;
		}
		++Pstr;
	}
	*Ptmp = '\0';
}

