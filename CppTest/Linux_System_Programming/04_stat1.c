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
 *  创建日期：2021-10-18 14:02:25
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    struct stat st;

    stat(argv[1], &st);

    //获取文件类型
    if (S_IFREG == (st.st_mode & S_IFMT))
    {
        printf("普通文件\n");
    }
    else if (S_IFDIR == (st.st_mode & S_IFMT))
    {
        printf("目录文件\n");
    }
    else if (S_IFLNK == (st.st_mode & S_IFMT))
    {
        printf("软连接\n");
    }
    else
    {
        printf("其他文件\n");
    }

    if (S_ISREG(st.st_mode))
    {
        printf("普通文件\n");
    }
    else if (S_ISDIR(st.st_mode))
    {
        printf("目录文件\n");
    }
    else if (S_ISLNK(st.st_mode))
    {
        printf("软连接\n");
    }
    else
    {
        printf("其他文件\n");
    }

    //获取文件权限
    if (st.st_mode & S_IRUSR)
    {
        printf("文件可读\n");
    }
    else if (st.st_mode & S_IWUSR)
    {
        printf("文件可写\n");
    }
    else if (st.st_mode & S_IXUSR)
    {
        printf("文件可执行\n");
    }

    return 0;
}
