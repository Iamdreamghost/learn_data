#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>


void get_time(char *stime)
{
	time_t timer;
	struct tm * tblock;
	
	time(&timer);
	tblock = localtime(&timer);
	sprintf(stime,"%u-%d-%d %d:%d:%d\n",tblock->tm_year+1900,tblock->tm_mon,tblock->tm_mday,tblock->tm_hour,tblock->tm_min,tblock->tm_sec);
}

int is_file(const char *path_file)
{
	FILE * fp = fopen(path_file,"r");
	if(fp == NULL)
	{
		return 0;
	}else
	{
		fclose(fp);
		return 1;
	}
}

int main()
{
		int c,i = 0;
		char time_data[50],tmp[50];
		char * file_name = "test.txt";
		FILE * time_log;


		if(is_file(file_name))
		{
			time_log = fopen(file_name,"a+");
			if(time_log == NULL)
					perror("time_log open fail!");
		
			
			while(fgets(tmp,50,time_log) != NULL)
			{
						i = atoi(strtok(tmp,","))+1;
			}
			
			
			while(1)
			{
	  			get_time(time_data);
					sprintf(tmp,"%d, %s",i,time_data);
					fwrite(tmp,(int)strlen(tmp),1,time_log);
					fflush(time_log);
					sleep(1);
					i++;
			}
		
		}else
		{
				time_log = fopen(file_name,"w+");	
				int i = 0;
				char tmp[50];
				while(1)
				{
	  			get_time(time_data);
					sprintf(tmp,"%d, %s",i,time_data);
					fwrite(tmp,(int)strlen(tmp),1,time_log);
					fflush(time_log);
					sleep(1);
					i++;
				}
		}
		
		fclose(time_log);
		return 0;
}
