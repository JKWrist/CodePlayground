#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static const char *skip(const char *in)
{
    printf("1111\n");
    while (in && *in && (unsigned char)*in <= 32)
    {
        printf("2222\n");
        in++;
    }
    printf("3333\n");
    return in;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-27 14:45:59
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    char str[] = "    10 asd    asdasd 1   23 [][ ;asd asd    ";

    printf("str %s\n", str);
    skip(str);
    printf("str %s\n", str);
    return 0;
}
