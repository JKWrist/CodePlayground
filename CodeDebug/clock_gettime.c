#include <stdio.h>
#include <time.h>
int main()
{
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);
    printf("CLOCK_REALTIME: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    //打印出来的时间跟 cat /proc/uptime 第一个参数一样
    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("CLOCK_MONOTONIC: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    printf("/n%d/n", time(NULL));

    return 0;
}