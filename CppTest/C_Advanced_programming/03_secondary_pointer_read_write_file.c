#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：getFileLines
 *  创建日期：2021-09-09 17:57:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int getFileLines(FILE *pFile)
{
    if (pFile == NULL)
    {
        return -1;
    }

    char buf[1024] = {0};
    int lines = 0;
    while (fgets(buf, 1024, pFile) != NULL)
    {
        lines++;
    }

    fseek(pFile, 0, SEEK_SET);
    return lines;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-09 17:57:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void readFileData(FILE *pFile, int len, char **pArray)
{
    if (pFile == NULL || len < 0 || pArray == NULL)
    {
        return;
    }
    char buf[1024] = {0};
    int index = 0;
    while (fgets(buf, 1024, pFile) != NULL)
    {
        int currentLen = strlen(buf) + 1;
        char *currentStrP = malloc(sizeof(char) * currentLen);
        strcpy(currentStrP, buf);
        pArray[index++] = currentStrP;
        memset(buf, 0, 1024);
    }
}

/****************************************************************
 *  函数名称：showData
 *  创建日期：2021-09-10 11:49:30
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void showData(char **pArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d行的数据为 %s", i + 1, pArray[i]);
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-10 11:52:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    FILE * pFile = fopen("./commit.sh", "r");
    if(pFile == NULL)
    {
        printf("文件打开失败\n");
        return;
    }

    int len = getFileLines(pFile);

    char **pArray = malloc(sizeof(char *) * len);

    readFileData(pFile, len, pArray);

    showData(pArray, len);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-09 17:57:42
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
