#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Num_1(char * P,int len);					//Ｐ:空间的地址　len:字节数 返回len个字节中１的个数

int main()
{
	char *p = (char*)malloc(sizeof(char)*1);		//申请一个char内存空间
	*p = 9;
	
	printf("%d\n",Num_1(p,1));
	
	free(p);

	return 0;
}

int Num_1(char * P,int len)
{
	unsigned char tmp,key=0x01;
	int i,j,count=0,k=0;
	for(i=0;i<len;i++)
	{
		tmp = P[i];
		for(j=0;j<8;j++)
		{
			if(tmp & key)
				count++;
			key<<=1;	
		}
		key = 0x01;
	}
	return count;
}
