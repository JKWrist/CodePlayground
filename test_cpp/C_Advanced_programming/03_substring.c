#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称: myStrstr1
 *  创建日期：2021-09-09 14:11:45
 *  作者：xujunze
 *  输入参数：src原字符串， substr子串
 *  输出参数：src
 *  返回值：找到子串位置  返回  包含以子串为首的匹配字符串
 *          未找到       返回  NULL
******************************************************************/
char *myStrstr1(char *src, char *substr)
{
    if (src == NULL || substr == NULL)
    {
        return NULL;
    }

    int num = 0;
    char * pSrc = src;
    char * pSubstr = substr;

    while(*pSrc != '\0')
    {
        if(*pSrc != *pSubstr)
        {
            pSrc++;
            num++;
            continue;
        }

        //创建两个临时指针做二次对比
        char *tmpStr = pSrc;
        char *tmpSubStr = pSubstr;
        while (*tmpSubStr != '\0')
        {
            if(*tmpStr != *tmpSubStr)
            {
                num++;
                pSrc++;
                break;
            }
            tmpSubStr++;
            tmpStr++;
        }

        if(*tmpSubStr == '\0')
        {
            return src + num;     
        }
    }
    return NULL;
}

/****************************************************************
 *  函数名称: myStrstr2
 *  创建日期：2021-09-09 14:11:45
 *  作者：xujunze
 *  输入参数：src原字符串， substr子串
 *  输出参数：src
 *  返回值：找到子串位置  返回  子串在原串中为位置
 *          未找到       返回  -1
******************************************************************/
int myStrstr2(char *src, char *substr)
{
    if(src == NULL || substr == NULL)
    {
        return -1;
    }

    int num = 0;
    while(*src != '\0')
    {
        if(*src != *substr)
        {
            src++;
            num++;   
            continue;
        }
        char * pSrc = src;
        char * pSubstr = substr;
        while(*pSubstr != '\0')
        {
            if(*pSrc != *pSubstr)
            {
                num++;
                src++;
                break;
            }
            pSrc++;
            pSubstr++;
        }

        if (*pSubstr == '\0')
        {
            return num;
        }
        
    }

    return -1;

}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-08 14:36:04
*/
int main()
{
    char *src = "asdasjk678mksjnb";
    char *sub = "678";

    printf("%s\n", myStrstr1(src, sub));

    printf("%d\n", myStrstr2(src, sub));
    return 0;
}
