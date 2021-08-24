#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
  int fd;
  char buffer[BUFFER_SIZE];
  if(argc != 2)
  {
    fprintf(stderr, "Usage : %s outfilename \n\a", argv[0]);
    exit(EXIT_FAILURE);
  }

  fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);

  dup2(fd, fileno(stdout));

  fprintf(stderr, "Now, please input string\n");
  fprintf(stderr, "To quit use Ctrl + D\n");

  while(1)
  {
    fgets(buffer, BUFFER_SIZE, stdin);
    if(feof(stdin))
      break;
    write(fileno(stdout), buffer, strlen(buffer));
  }

  return 0;

}
