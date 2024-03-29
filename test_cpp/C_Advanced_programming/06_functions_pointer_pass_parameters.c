#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:38:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printfText(void *data, void (*myprint)(void *))
{
    myprint(data);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:53:35
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void myPrintInt(void *data)
{
    int *num = data;
    printf("%d\n", *num);
}

void test01()
{
    int a = 10;
    printfText(&a, myPrintInt);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:57:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
struct Person
{
    int age;
    char name[64];
};

void myPrintPerson(void *data)
{
    struct Person *p = (struct Person *)data;
    printf("%d %s\n", p->age, p->name);
}

void test02()
{
    struct Person p = {16 , "Tom"};
    printfText(&p, myPrintPerson);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 21:38:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test01();

    test02();

    return 0;
}
