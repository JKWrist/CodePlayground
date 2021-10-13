#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//节点结构�?
struct LinkNode
{
   struct LinkNode * next; 
};

//链表结构�?
struct LList
{
   struct LinkNode pHeader;
   int m_size;
};

typedef void * LinkList;

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 17:01:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
//初�?�化链表
LinkList init_LinkList()
{
   struct LList * mylist = malloc(sizeof(struct LList));

   if (NULL == mylist)
   {
      return NULL;
   }

   mylist->pHeader.next = NULL;
   mylist->m_size = 0;

   return mylist;
}

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 17:06:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
//插入
void insert_LinkList(LinkList list, int pos, void * data)
{
   if(NULL == list || NULL == data)
   {
      return;
   }
   struct LList * mylist = list;

   if(pos < 0 || pos > mylist->m_size - 1 )
   {
      //无效位置尾插
      pos = mylist->m_size;
   }

   //找到插入的前驱节�?
   struct LinkNode * pCurrent = &mylist->pHeader;

   for (int i = 0; i < pos; i++)
   {
      pCurrent = pCurrent->next;
   }

   //用户前几�?字节我们定义一�?指针。用来存放指向下一�?元素的地址
   struct LinkNode *myNode = data;

   myNode->next = pCurrent->next;
   pCurrent->next = myNode;

   mylist->m_size++;
}

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 17:36:59
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
//遍历链表
void foreach_LinkList(LinkList list, void(*printData)(void *))
{
   if (NULL == list || NULL == printData)
   {
      return;
   }

   struct LList * mylist = list;

   struct LinkNode * pCurrect = mylist->pHeader.next;

   for (int i = 0; i < mylist->m_size; i++)
   {
      printData(pCurrect);
      pCurrect = pCurrect->next;
   }
   
}

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 18:18:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
void removeByPos_LinkList(LinkList list, int pos)
{
   if(NULL == list)
   {
      return;
   }

   struct LList * mylist = list;

   if(pos < 0 || pos > mylist->m_size)
   {
      return;
   }

   struct LinkNode * pPre = &mylist->pHeader;
   struct LinkNode * pCurrent = pPre->next;

   for (int i = 0; i < pos; i++)
   {
      pPre = pCurrent;
      pCurrent = pCurrent->next;
   }

   pPre->next = pCurrent->next;
   //free(pCurrent);

   mylist->m_size--;
}

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 19:01:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
//销毁数�?
void destory_Linklist(LinkList list)
{
   if(NULL == list)
   {
      return;
   }

   free(list);
   list = NULL;
}

struct Person
{
   void * node;
   char name[64];
   int age;
};

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 17:45:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
void myPrintPerson(void * data)
{
   struct Person * p = data;
   printf("姓名 : %s 年龄 : %d\n", p->name, p->age);
}

/****************************************************************
 *  函数名称�?
 *  创建日期�?2021-10-11 17:09:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
void test01()
{
   //初始化链表
   LinkList mylist = init_LinkList();

   //创建数据
   struct Person p1 = {NULL, "aaa", 10};
   struct Person p2 = {NULL, "bbb", 20};
   struct Person p3 = {NULL, "ccc", 30};
   struct Person p4 = {NULL, "ddd", 40};
   struct Person p5 = {NULL, "eee", 50};

   //插入节点
   insert_LinkList(mylist, 0, &p1);
   insert_LinkList(mylist, 1, &p2);
   insert_LinkList(mylist, 2, &p3);
   insert_LinkList(mylist, 3, &p4);
   insert_LinkList(mylist, 4, &p5);
   foreach_LinkList(mylist, myPrintPerson);

   //删除节点
   printf("删除节点\n\n\n\n\n\n");
   removeByPos_LinkList(mylist, 0);
   foreach_LinkList(mylist, myPrintPerson);

   destory_Linklist(mylist);
   mylist = NULL;
}

/****************************************************************
 *  函数名称：main
 *  创建日期�?2021-10-10 21:15:11
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：�?
******************************************************************/
int main()
{
   test01();
   
   return 0;
}
