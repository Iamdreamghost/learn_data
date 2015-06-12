#include<stdio.h>

int main(void)
{
	fprintf(stdout,"Hello 1\n");
	fprintf(stderr,"Hello 2\n");
	fprintf(stdout,"Hello 3");
	fprintf(stderr,"Hello 4");
	return 0;
}
