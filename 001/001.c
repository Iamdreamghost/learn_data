#include<stdio.h>
#include<stdlib.h>      //使用srand();
#include<time.h>        //使用rand();

int main()
{
	int i,rand_num,in_num;      //i计数，随机数rand_num, 输入数in_num


	srand((unsigned)time(NULL));    //以时间为种子，初始化随机数
//	rand_num=rand()%100+1;　　//生成(1-100)随机数
	rand_num=rand() % 100 + 1;
	printf("请输入１～１００的数字:\n");
	
	for( i=0; i<8; i++)
	{
		scanf("%d",&in_num);
		if(rand_num == in_num)
		{
			printf("恭喜您，您猜对了！\n");
			break;
		}else if(rand_num > in_num)
		{
			 printf("你输入的数有点小！你还剩下%d次机会！\n",7-i);
		}else
		{
		         printf("你输入的数有点大！你还剩下%d次机会！\n",7-i);
		}	
	}

	return 0;
}
