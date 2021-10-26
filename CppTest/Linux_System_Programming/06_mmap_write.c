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
 *  创建日期：2021-10-26 16:28:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//使用mmap函数完成两个不相干进程间通信
int main(int argc, char *argv[])
{
    //使用mmap函数简历共享映射区
    //void *
    //mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

    int fd = open("./data.txt", O_RDWR, 0777);
    if(fd < 0)
    {
        perror("open error");
        return -1;
    }

    int len = lseek(fd, 0, SEEK_END);

    printf("len %d\n", len);
    //建立共享映射区
    void * addr = mmap(NULL, len, PROT_READ|PROT_READ, MAP_SHARED, fd, 0);
    printf("addr %p\n", addr); 
    
    if (addr == MAP_FAILED)
    {
        perror("mmap error");
        return -1;
    }

    memcpy(addr, "0123456789", 11);
    return 0;
}
