//统计一个int空间中，位为1的个数
#include<stdio.h>

int Num_int(unsigned int num)	
{
	if(num == 0) return 0;
	
	return(num & 0x01)+Num_int(num>>1);
}

int main()
{
	printf("%d\n",Num_int(5));	
	return 0;
}
