#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "seqStack.h"

struct Person
{
    char name[64];
    int age;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 11:56:13
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    //初始化栈
    SeqStack mystack = init_SeqStack();

    //创建数据
    struct Person p1 = {"aaa", 10};
    struct Person p2 = {"bbb", 20};
    struct Person p3 = {"ccc", 30};
    struct Person p4 = {"ddd", 40};
    struct Person p5 = {"eee", 50};

    //入栈
    push_SeqStack(mystack, &p1);
    push_SeqStack(mystack, &p2);
    push_SeqStack(mystack, &p3);
    push_SeqStack(mystack, &p4);
    push_SeqStack(mystack, &p5);

    printf("栈的元素个数为 : %d\n", size_SeqStack(mystack));

    while (isEmpty_SeqStack(mystack) != 1)
    {
        struct Person *p = top_SeqStack(mystack);
        printf("%s %d\n", p->name, p->age);
        //出栈
        pop_SeqStack(mystack);
        printf("栈的元素个数为 : %d\n", size_SeqStack(mystack));
    }

    //销毁栈
    destory_SeqStack(mystack);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-11 19:35:17
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
