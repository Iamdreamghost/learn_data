#include<stdio.h>



int swap(int num)
{
	int m,k;
	k=0;
	while(1)
	{
		m = num%10;
		num = num/10;
		k = k*10 + m;
		if(num == 0)
			return k;
	}
}

int main()
{
	int data = swap(12156);
	printf("%d\n",data);	
}
