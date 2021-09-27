#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct mac
{
    char mac[12];
}MAC;
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-14 11:36:52
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //例1
    char dest[20] = {0};
    char src[] = "hello world12312312312";

    strncpy(dest, src, sizeof(dest));
    printf("%s\n", dest);  //溢出

    dest[19] = '\0';
    printf("%s\n", dest);

    //例2
    MAC * p = malloc(sizeof(MAC));
    memset(p, 0, sizeof(MAC));
    strncpy(p->mac, src, sizeof(p->mac));
    (p->mac)[sizeof(p->mac) - 1] = '\0';
    printf("%s\n", p->mac);

    free(p);
    p = NULL;

    return 0;
}
