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
 *  创建日期：2021-10-18 13:41:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
   struct stat st;
   
   if(argc < 2)
   {
      printf("1 argc : %d\n", argc);
   }
   else
      printf("2 argc : %d\n", argc);
   printf("3 argc : %d\n", argc);

   stat(argv[1], &st);
   printf("size:%d uid:%d, gid:%d", st.st_size, st.st_uid, st.st_gid);
   return 0;
}
