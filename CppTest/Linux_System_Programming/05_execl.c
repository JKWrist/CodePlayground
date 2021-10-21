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
 *  创建日期：2021-10-21 15:03:07
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建子进程
    pid_t pid = fork();
    if(pid <  0)
    {
        perror("fork errror");
        return -1;
    }
    else if(pid > 0)
    {
        printf("faather %d\n", getpid());
    }
    else if(pid == 0)
    {
        printf("child %d\n", getpid());
        //execl("/bin/ls", "ls", "-l", NULL);
        //如果是本程序编译的a.out 会造成死循环
        //execl("./test.out", "hello", "ni", "hoa", NULL);


    }

    return 0;
}
