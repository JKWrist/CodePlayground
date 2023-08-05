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
 *  创建日期：2021-10-21 16:05:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int fd = open("data.txt", O_RDWR);
    printf("%d\n", fd);

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
    }
    else if(pid > 0)
    {
        usleep(1000 * 500);
        printf("father\n");
        char buf[48] = {0};
        lseek(fd, 0, SEEK_SET);
        int ret = read(fd, buf, sizeof(buf));
        printf("father read buf %s %d\n", buf, fd);
    }
    else if(pid == 0)
    {
        char buf[48] = "child process write\n";
        lseek(fd, 0, SEEK_SET);
        int ret = write(fd, buf, sizeof(buf));
        printf("child write buf %s %d\n", buf, fd);
    }

    return 0;
}
