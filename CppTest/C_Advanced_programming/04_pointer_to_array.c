#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 10:47:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//数组指针的定义方式
//1、先定义数组类型，再通过定义数组指针
void test01()
{
    int arr[5] = {1, 2, 34, 5, 6};

    typedef int(ARRAY_TYPE)[5]; //ARRAY_TYPE 代表存放5个int元素数组 的数组类型

    ARRAY_TYPE arr2;
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = 100 + i;
        printf("%d ", arr2[i]);
    }

    printf("\n");

    //*arrP ==
    ARRAY_TYPE *arrP = &arr;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 10:47:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    //先定义数组指针类型，再通过类型定义数组指针
    int arr[5] = {1, 2, 3, 4, 5};
    typedef int(* ARRAY_POINT)[5];

    ARRAY_POINT p = &arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (*p)[i]);
    }
    printf("\n");
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-09-30 17:08:31
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
    //直接定义数组指针变量
    int arr[5] = {1, 2, 3, 4, 5};

    int (*p)[5] = &arr;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", (*p)[i]);
    }
    printf("\n");
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-09-30 10:47:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test01();
    //test02();
    
    test03();
    
    return 0;
}
