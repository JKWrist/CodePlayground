
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、指针的步长代表指针+1之后跳跃的字节数
void test01()
{
   char * p = NULL;
   printf("%p\n", p);
   printf("%p\n", p+1);

   double * p1 = NULL;
   printf("%p\n", p1);
   printf("%p\n", p1 + 1); 
}

//2、解引用的时候解出的字节数量
void test02()
{
   char buf[1024] = {0};
   int a = 1000;

   memcpy(buf +20, &a, sizeof(int));
   printf("%d\n", *(int *)(buf+20));
}

//步长练习，自定义数据类型练习
struct Person
{
   char name[128];  //0-127
   int age;          //128-131
   char sex;         //132-135
};

void test03()
{
   struct Person myPerson = {"xiaobai", 16, 'w'};
   char *p = &myPerson;
   printf("myPerson sex %c\n", p[132]);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 17:24:31
*/
int main()
{
   test01();
   test02();

   test03(); 
   return 0;
}
