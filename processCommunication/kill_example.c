#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_usr(int sig);

int main(int atgc, char *argv[])
{
  int i = 0;

  if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    printf("Cannot catch SIGUSR1\n");

  if(signal(SIGUSR2, sig_usr) == SIG_ERR)

  while(1)
  {
    printf("%2d", i);
    pause();
    i++;
  }
  return 0;
}

void sig_usr(int sig)
{
  if(sig == SIGUSR1)
    printf("Receive SIGUSR1\n");
  else if(sig == SIGUSR2)
    printf("Receive SIGURE2\n");
  else
    printf("undeclared signal\n");
}
