#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[])
{
  int i;
  alarm(2);
  for(int i =0; ;i++)
  {
    printf("%d\n", i);
    sleep(1);
  }

  return 0;
}
