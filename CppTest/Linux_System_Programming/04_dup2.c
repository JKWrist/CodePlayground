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
 *  创建日期：2021-10-18 19:24:47
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int fd = open(argv[1], O_RDWR, 0755);
    if (fd < 0)
    {
        perror("open error");
    }


    //调用dup函数复制fd
    int newfd = open(argv[2], O_RDWR, 0755);
    int ret = dup2(fd, newfd);
    printf("newfd : %d, fd : %d, ret : %d\n", newfd, fd, ret);

    write(fd, "hello world", strlen("hello world"));
    lseek(fd, 0, SEEK_SET);

    char buf[128] = {0};
    read(newfd, buf, sizeof(buf));
    printf("buf : %s, strlen(buf) : %d\n", buf, strlen(buf));
    
    return 0;
}
