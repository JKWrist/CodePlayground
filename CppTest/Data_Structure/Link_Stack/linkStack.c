#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//链表节点
struct LinkNode
{
    struct LinkNode * next;
};

struct LStack
{
    struct LinkNode headNode;
    int m_size;
};

typedef void * LinkStack;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:19:44
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//栈初始化
LinkStack init_stack()
{
    struct LStack *mystack = malloc(sizeof(struct LStack));

    mystack->headNode.next = NULL;
    mystack->m_size = 0;

    return mystack;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:22:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//入栈
void insert_stack(LinkStack stack, void * data)
{
    if(NULL == stack || NULL == data)
    {
        return;
    }

    struct LStack * mystack = stack;
    struct LinkNode * insertNode = data;
    insertNode->next = mystack->headNode.next;
    mystack->headNode.next = insertNode;

    mystack->m_size++;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:27:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//出栈
void * pop_stack(LinkStack stack)
{
    if(NULL == stack)
    {
        return NULL;
    }

    struct LStack * mystack = stack;
    struct LinkNode * freeNode = mystack->headNode.next;

    if (NULL == freeNode)
    {
        return NULL;
    }

    mystack->headNode.next = freeNode->next;

    mystack->m_size--;

    //这里本来是不应该返回的，只是为了少写一个返回栈顶元素的函数
    //仅提供本测试使用
    return freeNode;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:38:29
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//销毁
void destory_stack(LinkStack stack)
{
    if(NULL == stack)
    {
        return;
    }

    struct LStack * mystack = stack;

    mystack->headNode.next = NULL;
    mystack->m_size = 0;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:38:45
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//栈是否为空
int isEmpty_stack(LinkStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }
    struct LStack * mystack = stack;
    return 0 == mystack->m_size;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 15:40:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int size_stack(LinkStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }
    struct LStack *mystack = stack;
    return mystack->m_size;
}

struct Person
{
    void * next;
    char name[64];
    int age;
};

void test01()
{
    //初始化
    LinkStack pLinkStack = init_stack();

    printf("链表大小%d\n", size_stack(pLinkStack));

    struct Person p1 = {NULL, "aaa", 10};
    struct Person p2 = {NULL, "aaa", 20};
    struct Person p3 = {NULL, "aaa", 30};
    struct Person p4 = {NULL, "aaa", 40};
    struct Person p5 = {NULL, "aaa", 50};
    struct Person p6 = {NULL, "aaa", 60};

    insert_stack(pLinkStack, &p1);
    insert_stack(pLinkStack, &p2);
    insert_stack(pLinkStack, &p3);
    insert_stack(pLinkStack, &p4);
    insert_stack(pLinkStack, &p5);
    insert_stack(pLinkStack, &p6);

    while (1 != isEmpty_stack(pLinkStack) && -1 != isEmpty_stack(pLinkStack))
    {
        printf("stack size %d\n", size_stack(pLinkStack));
        struct Person *p = pop_stack(pLinkStack);
        printf("%s, %d\n", p->name, p->age);
    }
    
    destory_stack(pLinkStack);
}

int main()
{
    test01();

    return 0;
}