#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkNode
{
    int num;
    struct LinkNode *next;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 16:58:29
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    struct LinkNode *node1 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node2 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node3 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node4 = (struct LinkNode *)malloc(sizeof(struct LinkNode));
    struct LinkNode *node5 = (struct LinkNode *)malloc(sizeof(struct LinkNode));

    node1->num = 100;
    node2->num = 200;
    node3->num = 300;
    node4->num = 400;
    node5->num = 500;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    struct LinkNode * p = node1;

    while (NULL != p)
    {
        printf("%d ", p->num);
        p = p->next;
    }
    printf("\n");
}


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 16:58:29
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
