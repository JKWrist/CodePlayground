#ifndef __LINK_H__
#define __LINK_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode
{
    int num;
    struct LinkNode * next;
};

//初始化链表
struct LinkNode *initLinkList();

//遍历链表
void foreach_LinkList(struct LinkNode * pHeader);

//插入元素
void insert_Val(struct LinkNode * pHeader, int val);

//删除元素
void del_Val(struct LinkNode * pHeader, int val);

//清空链表
void clear_LinkList(struct LinkNode * pHeader);

//销毁链表
void destory_LinkList(struct LinkNode * pHeader);

#endif