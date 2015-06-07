#include<stdio.h>

void findmax(int s[],int t,int *k)
{
	int i,tmp=s[0];
	for(i=0;i<t;i++)
	{
		if(tmp < s[i])
		{
			tmp = s[i];
			*k = i;
		}
	}
}

int main()
{
		int a[10] = {12,23,34,45,56,67,78,11,22},k;
		findmax(a,10,&k);
		printf("Max:%d,k:%d\n",a[k],k+1);
		return 0;
}
