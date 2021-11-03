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
 *  创建日期：2021-10-18 11:34:38
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage a.out file_name\n");
    }

    //打开文件
    int fd = open(argv[1], O_RDWR);
    if (fd < 0)
    {
        perror("open error");
    }

    char buf[1024] = {0};
    int n = read(fd, buf, sizeof(buf));
    printf("FIRSR read n = %d, buf: %s\n", n, buf);

    memset(buf, 0, sizeof(buf));
    n = read(fd, buf, sizeof(buf));
    printf("SEXOND read n = %d, buf: %s\n", n, buf);

    close(fd);
    return 0;
}
