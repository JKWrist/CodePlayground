#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//节点结构体
struct LinkNode
{
    //数据域
    void * data;
    //指针域
    struct LinkNode * next;
};

//链表结构体
struct LList
{
    //头结点
    struct LinkNode pHeader;
    //链表长度
    int m_size;
};

typedef void * LinkList;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 20:25:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//初始化链表
LinkList init_LinkList()
{
    struct LList * myList = malloc(sizeof(struct LList));
    if(NULL == myList)
    {
        return NULL;
    }
    
    myList->pHeader.data = NULL;
    myList->pHeader.next = NULL;
    myList->m_size = 0;

    return myList;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-08 20:36:08
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//插入链表
void insert_LinkList(LinkList list, int pos, void * data)
{
    if(NULL == list || NULL == data)
    {
        return;
    }

    //将list还原成struct LList数据类型
    struct LList *myList = list;
    if(pos < 0 || pos > myList->m_size)
    {
        //无效位置，尾插
        pos = myList->m_size;
    }

    //找到插入节点的前驱节点位置
    struct LinkNode * pCurrent = &myList->pHeader;
    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }
    //pCurrent 要插入节点的前驱
    struct LinkNode * newNode = malloc(sizeof(struct LinkNode));
    newNode->data = data;
    newNode->next = NULL;
    
    //建立节点关系
    newNode->next = pCurrent->next;
    pCurrent->next = newNode;

    //更新链表长度
    myList->m_size++;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 20:32:05
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//遍历链表
void foreach_LinkList(LinkList list, void(* myForeach)(void *))
{
    if(NULL == list || NULL == myForeach)
    {
        return;
    }

    struct LList * mylist = list;
    struct LinkNode * pCurrent = mylist->pHeader.next;

    for (int i = 0; i < mylist->m_size; i++)
    {
        myForeach(pCurrent->data);
        pCurrent = pCurrent->next;
    }
    
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 20:40:30
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//删除链表 按位置
void removeByPosLinkList(LinkList list, int pos)
{
    if(NULL == list)
    {
        return;
    }

    struct LList * mylist = list;

    if (pos < 0 || pos > mylist->m_size)
    {
        return;
    }
    
    //记录待删除的节点
    struct LinkNode * pCurrent = &mylist->pHeader;

    for (int i = 0; i < pos; i++)
    {
        pCurrent = pCurrent->next;
    }

    struct LinkNode * pDel = pCurrent->next;
    pCurrent->next = pDel->next;

    free(pDel);
    pDel = NULL;

    //更新列表长度
    mylist->m_size--;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 20:50:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按值删除链表
void removeByValue_LinkList(LinkList list, void * data, int(*myCompare)(void *, void *))
{
    if(NULL == list || NULL == data)
    {
        return;
    }

    struct LList * mylist = list;
    //创建两个辅助指针
    struct LinkNode * pPrev = &mylist->pHeader;
    struct LinkNode * pCurrent = pPrev->next;

    for (int i = 0; i < mylist->m_size; i++)
    {
        if (myCompare(pCurrent->data, data))
        {
            //调试代码
            //printf("i = %d\n", i);
            pPrev->next = pCurrent->next;
            
            free(pCurrent);
            pCurrent = NULL;

            mylist->m_size--;
            break;
        }

        //辅助指针后移
        pPrev  = pCurrent;
        pCurrent = pCurrent->next;
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:08:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//清空链表
void clear_LinkList(LinkList list)
{
    if(NULL == list)
    {
        return;
    }
    struct LList * mylist = list;
    struct LinkNode * pCurrent = mylist->pHeader.next;

    for (int i = 0; i < mylist->m_size; i++)
    {
        struct LinkNode * pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    mylist->pHeader.next = NULL;
    mylist->m_size = 0;
    
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:19:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//返回链表长度
int size_LinkList(LinkList list)
{
    if(NULL == list)
    {
        return NULL;
    }

    struct LList * mylist = list;
    
    return mylist->m_size;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:22:02
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//销毁链表
void destory_LinkList(LinkList list)
{
    if(NULL == list)
    {
        return;
    }

    clear_LinkList(list);

    free(list);
    list = NULL;
}

struct Person
{
    char name[64];
    int age;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:24:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void myPrintPerson(void * data)
{
    struct Person * p = data;
    printf("姓名 ： %s, 年龄：%d\n", p->name, p->age);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:29:43
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int myComparePerson(void * data1, void * data2)
{
    if(NULL == data1 ||NULL == data2)
    {
        return -1;
    }

    struct Person * p1 = data1;
    struct Person * p2 = data2;
    
    return p1->age == p2->age && (0 == strcmp(p1->name, p2->name));
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-09 21:41:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    //准备数据
    struct Person p1 = {"安柏", 16};
    struct Person p2 = {"重云", 16};
    struct Person p3 = {"芭芭拉", 18};
    struct Person p4 = {"可莉", 14};
    struct Person p5 = {"琴团长", 25};
    struct Person p6 = {"宵宫", 21};

    LinkList mylist = init_LinkList();
    printf("链表的长度为 %d\n", size_LinkList(mylist));

    //初始数据
    printf("\n\n\n初始数据:\n");
    insert_LinkList(mylist, 0, &p1);
    insert_LinkList(mylist, 1, &p2);
    insert_LinkList(mylist, 2, &p3);
    insert_LinkList(mylist, 3, &p4);
    insert_LinkList(mylist, 4, &p5);
    insert_LinkList(mylist, 5, &p6);
    printf("链表的长度为 %d\n", size_LinkList(mylist));
    foreach_LinkList(mylist, myPrintPerson);

    printf("\n\n\n删除:\n");
    removeByPosLinkList(mylist, 4);
    foreach_LinkList(mylist, myPrintPerson);

    printf("\n\n\n删除特定元素:\n");
    struct Person p0 = {"宵宫", 21};
    removeByValue_LinkList(mylist, &p0, myComparePerson);
    foreach_LinkList(mylist, myPrintPerson);
    printf("链表的长度为 %d\n", size_LinkList(mylist));

    //清空数据
    printf("\n\n\n清空数据:\n");
    clear_LinkList(mylist);
    printf("链表的长度为 %d\n", size_LinkList(mylist));
    destory_LinkList(mylist);
    
    mylist = NULL;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-08 19:56:33
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
