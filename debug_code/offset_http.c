#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：get_start_end 获取数据的起始位置与结束位置
 *  创建日期：2021-12-15 14:13:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    FILE *fp = fopen("http.xml", "r");
    unsigned int startPos = 0;
    unsigned int endPos = 0;
    char *pStr;
    char c;

    do
    {
        if (feof(fp))
        {
            printf("Cannot find start of file\n");
            fclose(fp);
        }
        c = fgetc(fp);
        if (c != 0xd)
            continue;
        c = fgetc(fp);
        if (c != 0xa)
            continue;
        c = fgetc(fp);
        if (c != 0xd)
            continue;
        c = fgetc(fp);
        if (c != 0xa)
            continue;
        break;
    } while (1);
    (startPos) = ftell(fp);

    printf("1111111 %d\n", startPos);

    //------WebKitFormBoundary
    char LINE[1024];
    while (1)
    {
        memset(LINE, 0, sizeof(LINE));
        if (fgets(LINE, sizeof(LINE), fp))
        {
            //printf("LINE %s\n", LINE);
            if (strstr(LINE, "------WebKitFormBoundary"))
            {
                printf("find Boundary\n");
                break;
            }
        }
    }
    printf("LINE %s\n", LINE);
    (endPos) = ftell(fp);
    int len = strlen(LINE);
    printf("len %d\n", len);
    printf("2222222222 %d\n", endPos);
    // end = readpos - bondary -\r\n
    printf("2222222222 endPos - len -2 %d\n", endPos - len -2);

    char ch = fgetc(fp);

    fseek(fp, 0, SEEK_END);
    (endPos) = ftell(fp);
    endPos -= 6;
    printf("3333333333  file_end %d\n", endPos);
}
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
 *  函数名称：读取文件的每一行
 *  创建日期：2021-12-16 17:44:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    char LINE[1024];
    FILE *fp = fopen("http.xml", "r");
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
                printf("%s", pstr);
            }
        }
    }
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
    test01();

    test02();
}
