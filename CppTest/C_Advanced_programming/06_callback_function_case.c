#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//打印任意类型的数组
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 12:40:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void printAllArray(void * pArray, int eleSize, int len, void(*myPrint)(void *))
{
   char *p = pArray;
   for (int i = 0; i < len; i++)
   {
      char * eleAddr = p + eleSize * i;

      myPrint(eleAddr);
   }
}

void myPrintInt(void * data)
{
   int * num = data;
   printf("%d\n", *num);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 12:40:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
   int arr[5] = {1, 2, 3,4, 5};
   int len = sizeof(arr) / sizeof(int);
   printAllArray(arr, sizeof(int), len, myPrintInt);
}

struct Person
{
   char name[64];
   int age;
};

void myPrintPerson(void * data)
{
   struct Person * p = data;
   printf("%s %d\n", p->name, p->age);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 13:56:35
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
   struct Person personArray[4] =
   {
      {"aaa", 1},
      {"bbb", 2},
      {"ccc", 3},
      {"444", 4}
   };
   
   int len = sizeof(personArray) / sizeof(struct Person);
   printAllArray(personArray, sizeof(struct Person), len, myPrintPerson);
}

int findArrayEle(void * pArray, int eleSize, int len, void * data, int(*myCompare)(void *, void *))
{
   for (int i = 0; i < len; i++)
   {
      char *pElement = pArray + eleSize * i;
      if(0 == myCompare(pElement, data))
      {
         printf("find element\n");
         return 0;
      }
   }
   printf("not find element\n");
   return -1;
}

int myComparePerson(void * data1, void * data2)
{
   struct Person *p1 = data1;
   struct Person *p2 = data2;

   if( (0 == strcmp(p1->name, p2->name)) && (p1->age == p2->age))
   {
      return 0;
   }
   return -1;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 14:33:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
   struct Person personArray[4] =
       {
           {"aaa", 1},
           {"bbb", 2},
           {"ccc", 3},
           {"444", 4}};
   struct Person tmp = {"ccc", 2};

   struct Person tmp2 = {"ccc", 3};

   int len = sizeof(personArray) / sizeof(struct Person);
   findArrayEle(personArray, sizeof(struct Person), len, &tmp, myComparePerson);

   findArrayEle(personArray, sizeof(struct Person), len, &tmp2, myComparePerson);
}
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-03 12:40:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
   // test01();

   // test02();

   test03();

   return 0;
}
