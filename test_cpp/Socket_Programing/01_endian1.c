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
 *  创建日期：2021-11-16 20:51:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    union{
        short s;
        char c[sizeof(short)];
    }un;

    un.s = 0x0102;

    if(un.c[1] == 1 && un.c[0] == 2)
    {
        printf("little endian\n");
    }
    else if(un.c[1] == 2 &&un.c[0] == 1)
    {
        printf("big edndian\n");
    }
    else
    {
        printf("unknown\n");
    }
    

    return 0;
}
