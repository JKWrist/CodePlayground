#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person
{
    char *name;
    int age;
} myPerson;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:38:27
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
myPerson **allocateSpace(int num)
{
    if (num < 0)
    {
        return NULL;
    }
    myPerson **p1 = (myPerson **)malloc(sizeof(myPerson *) * num);
    for (int i = 0; i < num; i++)
    {
        p1[i] = (myPerson *)malloc(sizeof(myPerson));
        p1[i]->name = (char *)malloc(40);

        sprintf(p1[i]->name, "%s%d", "person_", i);
        p1[i]->age = i + 15;
        printf("创建结构体内存 %s %d\n", p1[i]->name, p1[i]->age);
    }
    return p1;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:47:30
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void freeSpace(myPerson **pArray, int num)
{
    if (pArray && num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            free(pArray[i]->name);
            pArray[i]->name = NULL;

            free(pArray[i]);
            pArray[i] = NULL;
        }
        free(pArray);
        pArray = NULL;
    }
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:57:40
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printPerson(myPerson **pArray, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("姓名： %s 年龄： %d\n", pArray[i]->name, pArray[i]->age);
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:38:27
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    myPerson **pArray = allocateSpace(10);
    printPerson(pArray, 10);
    //freeSpace(pArray, 10);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-30 21:38:27
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
