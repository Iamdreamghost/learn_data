#include<stdio.h>

int main()
{
	
	int a[3] = {0x11,0x12,0x13};
	int i = 0;
	printf("%x\n",a[i++]);
	printf("%x\n",a[i++]);
	printf("%x\n",a[i++]);
	return 0;
}
