#include "config.h"
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 11:05:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//获取有效行数
int getFileLines(char *filePath)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);

    FILE *file = fopen(filePath, "r");
    if (NULL == file)
    {
        perror("fopen error");
        return -1;
    }
    char buf[1024];
    int lines = 0;
    while (fgets(buf, 1024, file) != NULL)
    {
        if (isValidLines(buf))
        {
            lines++;
        }
        memset(buf, 0, 1024);
    }
    return lines;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 11:05:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//检测当前行是否为有效信息
int isValidLines(char *str)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);

    if (strchr(str, ':') == NULL)
    {
        return 0; //无效行
    }
    return 1;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 11:05:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//解析文件
void parseFile(char *filePath, int lines, struct ConfigInfo **configinfo)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);
    struct ConfigInfo *pInfo = (struct ConfigInfo *)calloc(lines, sizeof(struct ConfigInfo));
    if (pInfo == NULL)
    {
        perror("malloc error");
        return;
    }

    FILE *file = fopen(filePath, "r");
    if (NULL == file)
    {
        perror("fopen error");
        return;
    }
    fseek(file, 0,  SEEK_SET);
    char buf[1024] = {0};
    int index = 0;
    while (NULL != fgets(buf, 1024, file))
    {
        if (isValidLines(buf))
        {
            //sscanf(buf, "%s:%s", pInfo[index].key, pInfo[index].value);
            //此种方式行不通，因为sscanf读取具有贪婪性， 会把字符串都读到第一个字符数组中

            char * pos = strchr(buf, ':');
            strncpy(pInfo[index].key, buf, pos - buf);
            strncpy(pInfo[index].value, pos + 1, strlen(pos + 1) - 1);

            printf("key : %10s |value : %10s\n", pInfo[index].key, pInfo[index].value);
            index++;
            //printf("1111 %d\n", index);
        }
        memset(buf, 0, 1024);
    }
    fclose(file);

    *configinfo = pInfo;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 15:25:01
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printConfiginfo(struct ConfigInfo *configinfo, int len)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);
    if(configinfo == NULL)
    {
        return;
    }

    for (int i = 0; i < len; i++)
    {
        //printf("2222 %d\n", i);
        printf("key : %10s |value : %10s\n", configinfo[i].key, configinfo[i].value);
    }
    
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 11:55:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//根据key获取对应value
char *getInfoByKey(char *key, struct ConfigInfo *configinfo, int len)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);
    
    if (NULL == configinfo)
    {
        return NULL;
    }

    for (int i = 0; i < len; i++)
    {
        if(0 == strcmp(configinfo[i].key, key))
        {
            return configinfo[i].value;
        }
    }

    return NULL;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 11:55:30
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//释放内存
void freeConfigInfo(struct ConfigInfo *configinfo)
{
    printf("%d %s\n", __LINE__, __FUNCTION__);
    if (NULL != configinfo)
    {
        free(configinfo);
        configinfo = NULL;
    }
    
}