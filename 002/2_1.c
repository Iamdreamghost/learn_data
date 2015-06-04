/**************************************************
* 编写一个函数，将数组中的n个数反序存放。         *
***************************************************/
#include<stdio.h>

void my_swap(int * pa,int len);			//反序函数
void show(int * pa,int len);			//显示数组
int main()
{
	int a[] = {2,4,5,7,8,3,1};
	show(a,7);
	my_swap(a,7);
	show(a,7);
	return 0;
}

void my_swap(int * pa,int len)
{
	int left = 0, right = len - 1;
	while( left < right )
	{
		pa[left]  = pa[left] ^ pa[right];
		pa[right] = pa[left] ^ pa[right];
		pa[left]  = pa[left] ^ pa[right];
		
		left++;
		right--;
	}
}

void show(int * pa,int len)
{
	int i;
	for(i = 0;i<len;i++)
		printf("%d ",pa[i]);
	printf("\n");
}
