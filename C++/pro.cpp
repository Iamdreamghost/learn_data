#include<iostream>

void func(int *pa,unsigned int len)
{
	int left = 0,right = len;
	while(left < right)
	{
		int tmp;
		tmp       = pa[left];
		pa[left]  = pa[right];
		pa[right] = tmp;
		left++;
		right--;
	}

}

void play(int *pa,unsigned int len)
{
	for(int i=0;i<len;i++)
	{
		std::cout << pa[i] <<std::endl;
	}
}

int main()
{
	int a[] = {1,3,4,6,9,5,8};
	play(a,7);
	func(a,6);
	play(a,7);
	return 0;
}
