#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>    //read
#include <sys/select.h> //select
#include <sys/time.h>

#define BUF_SIZE 80

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-30 20:41:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    fd_set reads, temps;
    struct timeval timeout;

    FD_ZERO(&reads);
    FD_SET(0, &reads); //standard input

    while (1)
    {
        temps = reads;
        timeout.tv_sec = 3;
        timeout.tv_usec = 0;

        int result = select(1, &temps, 0, 0, &timeout);

        if (-1 == result)
        {
            puts("select() error");
            break;
        }
        else if (0 == result)
        {
            puts("Time-out!");
        }
        else
        {
            if (FD_ISSET(0, &temps))
            {
                char buf[BUF_SIZE] = {0};
                int strlen = read(0, buf, BUF_SIZE);
                buf[strlen] = '\0';
                printf("message from console : [%s]\n", buf);
            }
        }
    }

    return 0;
}
