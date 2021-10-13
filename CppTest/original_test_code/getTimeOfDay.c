#include <sys/time.h>
void f()
{
	for(int i = 0; i < 400000000; i++)
	{
		
	}
}
int main()
{
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	f();
	gettimeofday(&t2, NULL);
	//那么函数f运行所花的时间为
	long deltaT = (t2.tv_sec - t1.tv_sec) +(t2.tv_usec - t1.tv_usec)/1000000;
	// 微秒
	printf("deltaT = %lu\n", deltaT);
	return 0;
}