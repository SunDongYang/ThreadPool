#ifndef _CONDITION_H_
#define _CONDITION_H_

#include<pthread.h>

typedef struct condition
{
	pthread_mutex_t pmutex;		//互斥锁
	pthread_cond_t pcond;		//条件变量
}condition_t;

int condition_init(condition_t *cond);		//初始化条件变量
int condition_lock(condition_t *cond);		//锁定一个条件（其实是对互斥锁锁定）
int condition_unlock(condition_t *cond);
int condition_wait(condition_t *cond);
int condition_timedwait(condition_t *cond,const struct timespec *abstime);//具有超时功能
int condition_signal(condition_t *cond);
int condition_broadcast(condition_t *cond);
int condition_destroy(condition_t *cond);


#endif/*_CONDITION_H_*/
