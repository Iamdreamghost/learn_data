/*****************************************************
*输入一串字符，计算其中空格的个数.		     *
******************************************************/
#include<stdio.h>
#include<string.h>

int spa_len(const char *p);
int main()
{
	char str[100];
	printf("输入一串字符:\n");
	scanf("%[^\n]",str);
	printf("%d\n",spa_len(str));
	return 0;
}

int spa_len(const char *pstr)
{
	int i = 0;
	char tmp = pstr[0];
	while(tmp !='\0')
	{
		if(tmp == ' ')
			i++;
		pstr++;
		tmp = *pstr;
	}	
	return i;
}
