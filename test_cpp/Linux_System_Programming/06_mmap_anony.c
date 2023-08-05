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
 *  创建日期：2021-10-26 20:35:29
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    // void *
    // mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset);

    void * addr = mmap(NULL, 4096, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (MAP_FAILED == addr)
    {
        perror("mmap error");
        return -1;
    }
    
    //创建子进程
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
        return - 1;
    }
    else if (pid > 0)
    {
        memcpy(addr, "Hello World", strlen("Hello World"));
        wait(NULL);
    }
    else if (pid == 0)
    {
        sleep(1);
        char *p = (char *)addr;
        printf("%s\n", p);
    }
    return 0;
}
