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
 *  创建日期：2021-10-25 21:04:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建fifo文件
    //判断myfifo文件是否存在，若不存在则创建
    int ret = access("./myfifo", F_OK);
    if(ret != 0)
    {
        ret = mkfifo("./myfifo", 0777);
        if(ret < 0)
        {
            perror("mkfifo error");
        }
    }

    //打开文件
    int fd = open("./myfifo", O_RDWR);
    if(fd < 0)
    {
        perror("open error");
        return -1;
    }

    //读取fifo文件
    int n;
    char buf[64] = {0};
    int i;
    while(1)
    {
        memset(buf, 0x00, sizeof(buf));
        sprintf(buf, "%d:%s", i++, "hello world");
        n = write(fd, buf, sizeof(buf));
        printf("n=[%d], buf=[%s]\n", n, buf);
    }
    //关闭文件
    close(fd);

    return 0;
}
