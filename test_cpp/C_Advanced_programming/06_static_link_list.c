#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//不带头结点
struct LinkNode
{
    int num;
    struct LinkNode * next;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 16:13:27
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    struct LinkNode node1 = {10, NULL};
    struct LinkNode node2 = {20, NULL};
    struct LinkNode node3 = {30, NULL};
    struct LinkNode node4 = {40, NULL};

    //建立关系
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;

    //遍历列表
    struct LinkNode * pCurrent = &node1;
    while (pCurrent)
    {
        printf("%d\n", pCurrent->num);
        pCurrent = pCurrent->next;
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 16:13:27
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
