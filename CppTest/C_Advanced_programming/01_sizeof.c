#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、sizeof本质不是一个函数，是操作符
void test01()
{
    printf("size of int = %d\n", sizeof(int));
    //printf("size of int = %d\n", sizeof int);
    //expected parentheses around type name in sizeof expression

    double d = 3.14;
    printf("size of d = %d\n", sizeof d);
}

//2、sizeof 返回值类型 无符号整形 unsigned int
void test02()
{
    unsigned int a = 10;
    //warning: format specifies type 'int' but the argument has type
    //'unsigned long'[-Wformat] 
    printf("size of int = %d\n", sizeof(int));
}

//3、用途，统计数组长度，当数组名做函数参数时，会退化为指针，指向数组中第一个元素位置
void calculateArray(int arr[])
{
    printf("array length = %d\n", sizeof(arr));
}

void test03()
{
    int i_arr[20] = {1, 3, 2 ,3, 6};
    printf("array length %d\n", sizeof(i_arr));

    calculateArray(i_arr);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 10:37:29
*/
int main()
{
    test01();
    test02();
    test03();
    
    return 0;
}
