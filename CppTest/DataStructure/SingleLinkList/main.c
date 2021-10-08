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
    if(NULL == list || NULL == )
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
   
   return 0;
}
