#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:13:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void func(int a, char c)
{
    printf("hello world  %c\n", c);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:13:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    //1、先定义出函数类型，再通过类型定义函数指针
    typedef void(FUNC_TYPE)(int , char);

    FUNC_TYPE * pFunc = func;
    
    pFunc(10, 'a');

    //2、定义出函数指针类型，再通过类型定义定义变量
    typedef void(* FUNC_TYPE2)(int , char);
    FUNC_TYPE2 pFunc2 = func;
    pFunc(20, 'b');

    //3、直接定义函数值指针变量
    void (*pFunc3)(int , char);
    pFunc3 = func;
    pFunc(30, 'c');

}

void func1()
{
    printf("func1\n");
}

void func2()
{
    printf("func2\n");
}

void func3()
{
    printf("func3\n");
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-02 21:29:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//函数指针数组
void test02()
{
    void (*pArray[3])();

    pArray[0] = func1;
    pArray[1] = func2;
    pArray[2] = func3;
    int i = 0;
    while (i < 3)
    {
       pArray[i++]();
    }

}


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-02 21:13:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test01();

    test02();

    return 0;
}
