#include<stdio.h>
#include<stdlib.h>

void * encode(void * data,int * num);
int main()
{
	unsigned char array[] = {0x11,0x11,0x11,0x12,0x12,0x12,0x12,0x13,0x13,0x14,0x14};
	unsigned char * show_array;
	int i,len;
		
	len = sizeof(array)/sizeof(array[0]);
	show_array = encode(array,&len);
	len = sizeof(show_array)/sizeof(show_array[0]);
	printf("main len %d\n",len);

	for(i=0;i<len;i++)
	{
		printf("0x%x ",show_array[i]);
	}
	printf("\n");
	
}

void * encode(void * data,int * num)
{
	unsigned char * src_data = data;
	unsigned char * dst_data;
	unsigned char tmp;
	int i,j,count=1,len = *num;

	tmp = src_data[0];
	for(i=0;i<len;i++)
	{
		if(tmp != src_data[i])
		{
			count++;
			tmp=src_data[i];
		}
	}
	printf("differnet num:%d\n",count);
	
	dst_data = (unsigned char *)malloc(count*2);
	if(dst_data == NULL)
	{
		printf("error\n");
		return NULL;
	}
	
	j=0;
	dst_data[j++] = src_data[0];
	tmp = src_data[0];
	count = 1;
	for(i=0;i<len;i++)
	{
		if(tmp != src_data[i])
		{
			dst_data[j++] = count;
			dst_data[j++] = src_data[i];
			tmp = src_data[i];
			count = 1;
			continue;
		}
		count++;
	}
	
	dst_data[j] = count;
	count = sizeof(dst_data)/sizeof(dst_data[0]);
	printf("in encode count %d\n",count);
	return dst_data;
}
