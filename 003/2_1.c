#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int i,k,tmp,num,count=0;
	unsigned char * data;
	printf("Please input :\n");
	scanf("%d",&num);
	tmp = num;

	
	while(tmp)
	{
		tmp = tmp/10;
		count++;
	}
	
	data = (unsigned char *)malloc(count);
	while(count--)
	{
		tmp = num%10;
		data[count] = tmp;
		num=num/10;
		printf("%d",data[count]);
	}
	printf("\n");


//这里　pow函数无法使用
/*	
	tmp = 0;
	for(i=0;i<count;i++)
	{
		tmp = tmp + data[i]*pow(10,i);
	}
	printf("%d\n",tmp); */
	return 0;

}
