#include "seqStack.h"

//放在 .h文件
//到时提供给用户的话，用户就可以看到结构体元素

//放在 .c文件
//到时可以封装成库文件提供给用户，用户看不到这个里面的数据类型，封装较好

// struct SStack
// {
//     void *data[MAX]; //栈的数组
//     int m_size;
// };

// typedef void *SeqStack;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-11 20:21:59
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//初始化栈
SeqStack init_SeqStack()
{
    struct SStack * myStack = malloc(sizeof(struct SStack));

    if(NULL == myStack)
    {
        return NULL;
    }

    //初始化数组
    memset(myStack, 0, sizeof(void *) * MAX);

    //初始化栈大小
    myStack->m_size = 0;

    return myStack;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 09:39:05
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//入栈
void push_SeqStack(SeqStack stack, void *data)
{
    if(NULL == stack || NULL == data)
    {
        return;
    }

    struct SStack * myStack = stack;

    if (MAX == myStack->m_size)
    {
        return;
    }

    myStack->data[myStack->m_size] = data;
    myStack->m_size++;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 09:57:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//出栈
void pop_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return;
    }

    struct SStack * myStack = stack;

    if(0 == myStack->m_size)
    {
        return;
    }

    myStack->data[myStack->m_size - 1] = NULL;
    myStack->m_size--;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 10:07:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//返回栈顶
void *top_SeqStack(SeqStack stack)
{
    if(NULL == stack)
    {
        return NULL;
    }

    struct SStack * myStack = stack;
    return myStack->data[myStack->m_size - 1];
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 10:07:57
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//返回栈大小
int size_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }

    struct SStack * myStack = stack;
    return myStack->m_size;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 10:08:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//判断栈是否为空
int isEmpty_SeqStact(SeqStack stack)
{
    if (NULL == stack)
    {
        return -1;
    }
    struct SStack *myStack = stack;
    
    return 0 == myStack->m_size;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 10:08:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//销毁栈
void destory_SeqStack(SeqStack stack)
{
    if (NULL == stack)
    {
        return;
    }

    struct SStack * 
}