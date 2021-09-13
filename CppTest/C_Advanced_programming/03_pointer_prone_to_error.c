#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-09 15:06:23
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    char *p = malloc(sizeof(char) * 64);
    memset(p, 0, 64);
    char *pp = p; //通过创建临时指针操作内存，防止出错
    for (int i = 0; i < 10; i++)
    {
        *pp = i + 97;
        printf("%c\n", *pp);
        pp++;
    }

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-09 15:05:22
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    test01();
    return 0;
}