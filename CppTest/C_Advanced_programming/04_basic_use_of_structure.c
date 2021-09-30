#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Person1
{
    char name[20];
    int age;
};
typedef struct Person1 myPerson1;

typedef struct Person2
{
    char name[20];
    int age;
} myPerson2;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 20:04:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    myPerson1 person1 = {"Tom", 12};
    myPerson2 person2 = {"Jerry", 18};

    printf("姓名:%-20s|年龄：%d\n", person1.name, person1.age);
    printf("姓名:%-20s|年龄：%d\n", person2.name, person2.age);
}

struct Person3
{
    char name[20];
    int age;
}myPerson3 = {"Xiaobai", 16};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 20:04:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    printf("姓名:%-20s|年龄：%d\n", myPerson3.name, myPerson3.age);
}

//匿名结构体
struct 
{
    char name[64];
    int age;
}myPerson4 = {"bbb", 30};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 20:22:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
    printf("姓名:%-20s|年龄：%d\n", myPerson4.name, myPerson4.age);
}


/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 20:24:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//结构体创建
void test04()
{
    //创建在栈上
    myPerson1 person1 = {"aaaa", 123};
    printf("姓名:%-20s|年龄：%d\n", person1.name, person1.age);


    //创建在堆上
    myPerson1 *person2 = (myPerson1 *)malloc(sizeof(myPerson1));
    memset(person2, 0, sizeof(myPerson1));
    strcpy(person2->name, "bbb");
    person2->age = 20;
    printf("姓名:%-20s|年龄：%d\n", person2->name, person2->age);

    if(person2)
    {
        free(person2);
        person2 = NULL;
    }
}

void printArray(myPerson1 personArray[], int num) 
{
    for (int i = 0; i < num; i++)
    {
        printf("姓名:%-20s|年龄：%d\n", personArray[i].name, personArray[i].age);
    }
    
};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 20:41:40
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//结构体变量数组创建
void test05()
{
    myPerson1 personArray1[3] = { {"asaa", 18},
                                   {"bbbb", 19},
                                   {"cccc", 20} }; 
    printArray(personArray1, sizeof(personArray1) / sizeof(myPerson1));

    myPerson1 *pArray = (myPerson1 *)malloc(4 * sizeof(myPerson1));
    for (int i = 0; i < 4; i++)
    {
        sprintf(pArray[i].name, "%s%d", "name_", i);
        pArray[i].age = 18 + i;
    }
    printArray(pArray, 4);
    if (pArray)
    {
        free(pArray);
        pArray = NULL;
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-30 20:04:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
//    test01();
//    test02();
//    test03();
//    test04();
   test05();

    return 0;
}
