//动态数组

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dynamicArray.h"

struct Person
{
   char name[64];
   int age;
};
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 16:31:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void myPrintPerson(void *data)
{
   struct Person * p = data;
   printf("姓名:%s 年龄:%d\n", p->name, p->age);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 16:31:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int myComparePerson(void * data1, void * data2)
{
   struct Person * p1 = data1;
   struct Person * p2 = data2;
   return (0 == strcmp(p1->name, p2->name)) && p1->age == p2->age;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-08 16:31:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
   struct dynamicArray * array = init_DynamicArray(4);

   //准备数据
   struct Person p1 = {"安柏",  16};
   struct Person p2 = {"重云",  16};
   struct Person p3 = {"芭芭拉",  18};
   struct Person p4 = {"可莉",  14};
   struct Person p5 = {"琴团长",  25};
   struct Person p6 = {"宵宫",  21};

   printf("插入数据前：容量：%d  大小：%d\n", array->m_capacity, array->m_size);
   insert_DynamicArray(array, 0, &p1);
   insert_DynamicArray(array, 0, &p2);
   insert_DynamicArray(array, 1, &p3);
   insert_DynamicArray(array, 0, &p4);
   insert_DynamicArray(array, -1, &p5);
   insert_DynamicArray(array, 2, &p6);

   //可莉 重云, 宵宫 芭芭拉,  安柏 琴团长

   //遍历数组
   foreach_DynamicArray(array, myPrintPerson);
   printf("\n\n");

   removeByPos_DynamicArray(array, 2);
   foreach_DynamicArray(array, myPrintPerson);
   printf("\n\n");

   struct Person p0 = {"可莉", 14};
   removeByValue_DynamicArray(array, &p0, myComparePerson);
   foreach_DynamicArray(array, myPrintPerson);
   printf("\n\n");

   //有一个不好的地方是可以直接访问其中的数据
   // array->m_capacity= 0;
   // array->m_size = 0;
   // array->pAddr = NULL;

   //每个函数都要测试到，经过测试，如下函数就发生了崩溃问题
   //销毁数组
   destory_DynamicArray(array);
   foreach_DynamicArray(array, myPrintPerson);
   //array = NULL;
   
   return 0;
}
