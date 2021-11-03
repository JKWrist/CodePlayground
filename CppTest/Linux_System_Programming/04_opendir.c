#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-18 15:10:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//循环遍历下面的额每一个文件夹  ./a.out ..
void fake_tree(char *pName)
{
    DIR *pDir = opendir(pName);
    struct dirent *p;
    char buf[1024] = {0};
    while (NULL != (p = readdir(pDir)))
    {
        memset(buf, 0, sizeof(buf));

        if (0 == strcmp(p->d_name, ".") ||
            0 == strcmp(p->d_name, ".."))
        {
            continue;
        }
        //printf("[name] : %s\n", p->d_name);
        strcpy(buf, pName);
        strcat(buf, "/");
        strcat(buf, p->d_name);
        printf("[buf] : %s\n", buf);

        if (DT_DIR == p->d_type)
        {
            fake_tree(buf);
        }
    }
    closedir(pDir);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-18 14:41:05
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //打开目录

    fake_tree(argv[1]);

    return 0;
}
