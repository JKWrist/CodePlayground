#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
  sleep(5);
  struct timespec time1 = {0,0};
  clock_gettime(CLOCK_REALTIME, &time1);
  printf("CLOCK_REALTIME:%lu, %lu\n", time1.tv_sec, time1.tv_nsec);

  clock_gettime(CLOCK_MONOTONIC, &time1);
  printf("CLOCK_REALTIME:%lu, %lu\n", time1.tv_sec, time1.tv_nsec);
  
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
  printf("CLOCK_REALTIME:%lu, %lu\n", time1.tv_sec, time1.tv_nsec);
  
  clock_gettime(CLOCK_THREAD_CPUTIME_ID, &time1);
  printf("CLOCK_REALTIME:%lu, %lu\n", time1.tv_sec, time1.tv_nsec);

  return 0;
}



