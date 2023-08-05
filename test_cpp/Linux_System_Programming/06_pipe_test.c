#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/****************************************************************
 *  函数名称：test_close_read
 *  创建日期：2021-10-22 17:15:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test_close_read()
{
    //int pipe(int pipefd[2]);

    //创建管道
    int fd[2] = {0};
    int ret = pipe(fd);

    if(ret < 0)
    {
        perror("pipe error");
        return;
    }

    printf("pipe read %d %d\n", fd[0], fd[1]);

    //关闭写端
    close(fd[1]);

    //设置管道读端为非阻塞
    int flag = fcntl(fd[0], F_GETFL);
    flag |= O_NONBLOCK;
    fcntl(fd[0], F_SETFL, flag);

    char buf[64] = {0};
    int n = read(fd[0], buf, sizeof(buf));
    printf("read over, n = %d, buf = %s\n", n, buf);
}

/****************************************************************
 *  函数名称：test_close_write
 *  创建日期：2021-10-22 17:15:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test_close_write()
{
    //int pipe(int pipefd[2]);

    //创建管道
    int fd[2] = {0};
    int ret = pipe(fd);

    if(ret < 0)
    {
        perror("pipe error");
        return;
    }

    printf("pipe write %d %d\n", fd[0], fd[1]);

    //关闭读端
    //close(fd[0]);

    // //设置管道写端为非阻塞
    // int flag = fcntl(fd[1], F_GETFL);
    // flag |= O_NONBLOCK;
    // fcntl(fd[1], F_SETFL, flag);

    char buf[64] = "tomorrow is a new day";

 	int n = write(fd[1], buf, sizeof(buf));
    printf("write over, n = %d, buf = %s\n", n, buf);

	int i = 0;
    while(1)
    {    
        int n = write(fd[1], buf, sizeof(buf));
        printf("i++ %d write over, n = %d, buf = %s\n", i++, n, buf);
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-22 16:20:45
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //读
    test_close_read();

    //写
    //test_close_write();

    return 0;
}
