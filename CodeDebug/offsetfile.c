#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-12-15 14:13:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
static char *get_line(FILE *fp, char *s, int size)
{
    char *pstr = NULL;
    int len = 0;
    char *p = NULL;
    while (1)
    {
        if (!(p = fgets(s, size, fp)) || !(len = strlen(s)) || s[len - 1] != '\n')
        {
            printf("get_line %s %d len = %d [%c]\n", s, size, len, s[len - 1]);
            return NULL;
        }

        if (strlen(s))
        {
            break;
        }
    }
    return s;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-15 14:13:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    char LINE[1024];
    FILE *fp = fopen("config.xml", "r");
    if (NULL == fp)
    {
        printf("fd error\n");
    }

    char *pstr = NULL;

    while (!feof(fp))
    {
        memset(LINE, 0, sizeof(LINE));
        pstr = get_line(fp, LINE, sizeof(LINE)); //get one line from the file
        if (pstr != NULL)
        {
            if (strlen(pstr) > 0)
            {
                printf("33333 pstr %s\n", pstr);
            }
        }
    }
}
