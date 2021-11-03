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
        // execl("/usr/bin/gcc", "gcc", "-o", "test.out", "05_test.c", NULL);
        
        // printf("111\n");

        //注：execl的原理是用一个新的程序替换了当前进程的代码段，数据段，堆和栈
        //原有进程空间没有发生变化，变没有创建你新的进程， 进程pid没有变化
        // execl("./test.out", "test.out", "ni", "hao", NULL);

        //execlp("ls", "ls", "-l", NULL);
        //execlp("./test.out", "Testing", "-l", NULL);

        execl("./test.out", "Testing", "-l", "ni", "hao", NULL);
    }

    return 0;
}
