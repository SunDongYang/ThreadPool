#include"threadpool.h"

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

//编程测试驱动

void *nytask(void *arg)
{
	printf("thread x%0x is working on task %d\n",(int)pthread_self(),*(int*)arg);
	sleep(1);
	free(arg);
	return NULL;
}

int main(void)
{
	threadpool_t pool;
	threadpool_init(&pool,3);
	

	for(int i=0;i<100;i++)
	{
		int *arg = (int*)malloc(sizeof(int));
		*arg = i;
		threadpool_add_task(&pool,nytask,arg);//防止其他线程改变i，用arg替换i
 	}
	
//	sleep(15);
	threadpool_destroy(&pool);
	return 0;
}
