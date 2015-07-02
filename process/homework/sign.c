#include<stdio.h>
#include<signal.h>

void sign_print()
{
	printf("printf sign \n");
}
int main()
{
	signal(SIGINT,sign_print);
	for(;;);
	return 0;
}
