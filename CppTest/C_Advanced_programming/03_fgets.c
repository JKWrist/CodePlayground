#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-10 11:17:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    char str[5];
    printf("请输入str: ");
    fgets(str, sizeof(str), stdin);
    printf("str = \"%s\"\n", str);
    return 0;
}
