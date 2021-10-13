#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *func1(void * f1)

{
	puts("我是第一个线程！我采用return的方式结束自己。");
	return (void*)770880;
}

void *func2(void * f2)

{
	puts("我是第二个线程！我采用pthread_exit的方式结束自己。");
	pthread_exit((void*)1314);
}

void *func3(void * f3)

{
	puts("我是第三个线程！我采用pthread_cancel的方式结束自己。");
	while (1)//可能会发生线程执行完但是主线程还没有开始调用pthread_cancel函数。
		pthread_testcancel();//主动设置取消点
	return (void*)520;
}

int main(void)
{
	pthread_t pth[3];
	void *i;
	pthread_create((pth + 0), NULL, func1, NULL);
	pthread_join(pth[0], (void**)&i);
	printf("线程一的退出状态：i = %d.\n", (int)i);
	pthread_create((pth + 1), NULL, func2, NULL);
	pthread_join(pth[1], (void**)&i);
	printf("线程二的退出状态：i = %d.\n", (int)i);
	pthread_create((pth + 2), NULL, func3, NULL);
	pthread_cancel(pth[2]);//杀死
	pthread_join(pth[2], (void**)&i);
	printf("线程三的退出状态：i = %d.\n", (int)i);
	return 0;
}