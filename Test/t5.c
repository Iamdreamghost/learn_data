#include<stdio.h>

int main()
{
	char buffer[6];
	fgets(buffer,6,stdin);
	printf("%s",buffer);
	return 0;
}
