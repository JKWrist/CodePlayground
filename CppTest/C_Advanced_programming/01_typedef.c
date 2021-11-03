#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、简化关键字
struct Person
{
    char name[64];
    int age;
};
typedef struct Person myPerson;

//2、区分数据类型
void test2()
{
    typedef char * PCHAR;
    PCHAR p1, p2;
    printf("%p %p\n", p1, p2);
    char *p3, p4;  //typedef重新定义的话就不会出现下面这种情况
    printf("%p %p\n", p3, p4);
}

//3、提高移植性
typedef int MYINT;
void test3()
{
    MYINT a =10;
    MYINT b =20;
}

/*
* Author:xujunze
* Description: 使用typedef
* Date: Create in 2021-09-04 09:50:40
*/
int main()
{
   struct Person sPerson1 = {"XiaoMing", 18};
   myPerson sPerson2 = {"XiaoHong", 14};

   printf("%s, %d\n", sPerson1.name, sPerson1.age);
   printf("%s, %d\n", sPerson2.name, sPerson2.age);

   test2();
   test3();
   return 0;
}
