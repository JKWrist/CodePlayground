#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    char name[64];
    int age;
};
/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:06:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    struct Person p1 = {"Tom", 18};
    struct Person p2 = {"Jerry", 16};

    p2 = p1;

    printf("person1的姓名：%-20s  |年龄 ：%d\n", p1.name, p1.age);
    printf("person2的姓名：%-20s  |年龄 ：%d\n", p2.name, p2.age);
}

struct Person2
{
    char * name;
    int age;
};
/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 21:06:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    struct Person2 *p1 = (struct Person2 *)malloc(sizeof(struct Person2));
    struct Person2 *p2 = (struct Person2 *)malloc(sizeof(struct Person2));
    p1->name = (char *)malloc(20);
    strcpy(p1->name, "name1");
    p1->age = 16;
    printf("person1的姓名：%-20s  |年龄 ：%d\n", p1->name, p1->age);




    //p1 = p2; //系统提供的赋值操作是简单的浅拷贝 
    
    //我们需要做手动赋值，提供深拷贝

    p2->name = (char *)malloc(strlen(p1->name) + 1);
    strcpy(p2->name, p1->name);
    p2->age = p1->age;
    printf("person2的姓名：%-20s  |年龄 ：%d\n", p2->name, p2->age);
    

    if (p1->name)
    {
        free(p1->name);
        //p1->name = NULL;
    }

    if (p1)
    {
        free(p1);
        p1 = NULL;
    }

    if (p2->name)
    {
        free(p2->name);
        //p2->name = NULL;
    }

    if (p2)
    {
        free(p2);
        p2 = NULL;
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-30 21:06:50
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
