#include "link.h"

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//初始化链表
struct LinkNode *initLinkList()
{
    struct LinkNode *p = malloc(sizeof(struct LinkNode));
    if (NULL == p)
    {
        return NULL;
    }

    //初始化头结点
    p->next = NULL;

    struct LinkNode *pTail = p;
    int val = -1;
    while (1)
    {
        //让用户初始化几个节点， 如果用户输入的是-1，代表插入结束
        printf("请初始化链表， 如果输入-1代表结束\n");
        scanf("%d", &val);

        if (-1 == val)
        {
            break;
        }

        //如果输入不是-1， 插入节点到链表中
        struct LinkNode *newNode = (struct LinkNode *)malloc(sizeof(struct LinkNode));
        newNode->num = val;
        newNode->next = NULL;

        pTail->next = newNode;
        pTail = newNode;
    }

    return p;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//遍历链表
void foreach_LinkList(struct LinkNode *pHeader)
{
    if (NULL == pHeader)
    {
        return;
    }

    struct LinkNode *pCurrent = pHeader->next;

    while (pCurrent)
    {
        printf("%d ", pCurrent->num);
        pCurrent = pCurrent->next;
    }
    printf("\n");
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//插入元素
void insert_Val(struct LinkNode *pHeader, int val)
{
    if (NULL == pHeader)
    {
        return;
    }

    struct LinkNode *pTail = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    pTail->num = val;
    pTail->next = NULL;

    struct LinkNode *pCurrect = pHeader;

    while (pCurrect)
    {
        if (NULL == pCurrect->next)
        {
            pCurrect->next = pTail;
            break;
        }
        pCurrect = pCurrect->next;
    }
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:13
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//删除元素
void del_Val(struct LinkNode *pHeader, int val)
{
    if (NULL == pHeader)
    {
        return;
    }
    //创建两个辅助指针变量
    struct LinkNode *pPre = pHeader;
    struct LinkNode *pCurrent = pHeader->next;

    while (pCurrent)
    {
        if (val == pCurrent->num)
        {
            break;
        }
        pPre = pCurrent;
        pCurrent = pCurrent->next;
    }

    if (NULL == pCurrent)
    {
        return;
    }

    //更改指针的指向进行删除
    pPre->next = pCurrent->next;
    free(pCurrent);
    pCurrent = NULL;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:16
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//清空链表
void clear_LinkList(struct LinkNode *pHeader)
{
    if (NULL == pHeader)
    {
        return;
    }

    struct LinkNode *pCurrent = pHeader->next;

    while (pCurrent)
    {
        struct LinkNode *nextNode = pCurrent->next;

        free(pCurrent);
        pCurrent = nextNode;
    }

    pHeader->next = NULL;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 18:04:20
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//销毁链表
void destory_LinkList(struct LinkNode *pHeader)
{
    if (NULL == pHeader)
    {
        return;
    }

    clear_LinkList(pHeader);

    free(pHeader);
    pHeader = NULL;
}