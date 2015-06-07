#include<stdio.h>
#include<stdlib.h>

void * decode(void * data,int *num);

int main()
{
	unsigned char array[] = {0x11,0x3,0x12,0x4,0x13,0x5};
	int num = sizeof(array)/sizeof(array[0]);
	unsigned char * decode_data;
	int i;

	decode_data = decode(array,&num);
	for(i=0;i<num;i++)
	{
		printf("0x%x  ",decode_data[i]);
	}
	printf("\n");
	
	return 0;
}

void *decode(void * data,int * num)
{
		unsigned char * src_data = (unsigned char *)data;
		int src_len = *num;
		int dst_len;
		unsigned char * dst_data;
		unsigned char tmp;
		int i,j,count;

		if(data == NULL)
		{
			fprintf(stderr,"input data is empty...\n");
			return NULL;
		}

		if(src_len % 2)
		{
			fprintf(stderr,"input data num is odd.\n");
			return NULL;
		}

		dst_len = 0;
		for(i = 1; i < src_len; i+=2)
		{
			dst_len += src_data[i];
		}
		printf("the decode len is %d\n",dst_len);

		dst_data = (unsigned char *)malloc(dst_len);
		if(dst_data == NULL)
		{
			fprintf(stderr,"malloc encode data error!\n");
			return NULL;
		}
		*num = dst_len;
		count = 0;
		for(i = 1; i < src_len; i+=2)
		{
			tmp = src_data[i-1];
			for(j=0;j<src_data[i];j++)
			{
				dst_data[count++] = tmp;
			}
		}
	
		return dst_data;
}

