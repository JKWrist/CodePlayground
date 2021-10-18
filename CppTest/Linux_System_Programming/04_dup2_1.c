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
 *  创建日期：2021-10-18 20:11:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR, 0755);
    if(fd < 0)
    {
        perror("open error");
    }
    //调用dup2函数实现文件重定向操作
    dup2(fd, STDOUT_FILENO);
    printf("dup2 hell\n");
    close(fd);
    return 0;
}
