#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-13 15:19:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
   if(argc != 2)
   {
      printf("Usage a.out file_name\n");
   }

   int fd = open(argv[1], O_RDWR|O_CREAT, 0777);
   if(fd < 0)
   {
      perror("open error");
      return -1;
   }

   write(fd, "hello world", strlen("hello world"));
   lseek(fd, 0, SEEK_SET);
   
   char buf[1024] = {0};
   int n = read(fd, buf, sizeof(buf));
   printf("n = %d, buf : %s", n, buf);
   close(fd);

   return 0;
}
