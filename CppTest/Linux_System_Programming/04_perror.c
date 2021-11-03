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
 *  创建日期：2021-10-18 11:46:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //打开文件
   int fd = open(argv[1], O_RDWR);
   if(fd < 0)
   {
       perror("open error");
       if (errno == ENOENT)
       {
           printf("same \n");
       }
   }
   int n = 0;
   for (int i = 0; i < 64; i++)
   {
       errno = i;
       printf("[%d] [%s]\n", errno, strerror(errno));
   }
   return 0;
}
