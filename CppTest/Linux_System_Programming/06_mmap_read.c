#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/mman.h>
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-26 16:26:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//使用mmap函数完成两个不相干进程间通信
int main(int argc, char *argv[])
{
    //void *
    //mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);
    int fd= open("data.txt", O_RDWR, 0777);
    if(fd < 0)
    {
        perror("open error");
        return -1;
    }

    int len = lseek(fd, 0, SEEK_END);
    void * addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
    if(MAP_FAILED == addr)
    {
        perror("map error");
        return -1;
    }

    char buf[64] = {0};
    memcpy(buf, addr, 10);
    printf("%s\n", buf);
    return 0;
}
