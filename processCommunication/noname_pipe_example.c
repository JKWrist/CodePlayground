#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  pid_t pid;
  int templi;
  int pipedes[2];
  char s[13] = "test message!";
  char d[13] = {0};

  if((pipe(pipedes)) == -1)
  {
    perror("pipe");
    exit(EXIT_FAILURE);
  }

  if((pid  = fork()) == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if(pid == 0)
  {
    printf("now write data to pipe\n");
    if((write(pipedes[1], s, 13)) == -1)
    {
      perror("write");
      exit(EXIT_FAILURE);
    }
    else
    {
      printf("the write data is %s\n", s);
    }
  }
  else if(pid > 0)
  {
    sleep(2);
    printf("now read data from pipe\n");
    if((read(pipedes[0], d, 13)) == -1)
    {
      perror("read");
      exit(EXIT_FAILURE);
    }
    else
    {
      printf("the data form pipe is %s\n", d);
    }
  }

  return 0;

}
