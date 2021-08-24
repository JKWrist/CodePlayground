#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define FIFO "fifo"

int main(int argc, char *argv[])
{
  pid_t pid;
  char buffer[100] = {0};
  int fd;

  unlink(FIFO);
  mkfifo(FIFO, 0744);

  if((pid = fork()) > 0)
  {
    char s[] = "Hello!";
    fd = open(FIFO, O_WRONLY);

    write(fd, s, sizeof(s));

    printf("%d\n", sizeof(s));

    close(fd);
  }
  else if(pid == 0)
  {
    sleep(2);
    fd = open(FIFO, O_RDONLY);
    read(fd, buffer, 80);
    printf("this is child, read data is:%s\n", buffer);
    
    close(fd);
    printf("child's pid is %d\n", getpid());
    
  }
}
