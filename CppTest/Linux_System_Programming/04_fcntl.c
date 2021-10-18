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
 *  创建日期：2021-10-18 20:20:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int fd = open(argv[1],  O_RDWR, 0755);
    if(fd < 0)
    {
        perror("open error");
    }

    int flags = fcntl(fd, F_GETFL, 0);
    printf("%d %o %x\n", flags, flags, flags);
    
    flags = flags | O_APPEND;
    fcntl(fd, F_SETFL, flags);

    write(fd, "fcntl", strlen("fcntl"));
    close(fd);
    
    return 0;
}
