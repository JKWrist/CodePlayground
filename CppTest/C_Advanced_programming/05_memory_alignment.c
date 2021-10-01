#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(show)
//查看当前对齐模数， 对齐模数是可以修改的， 改成2的N次方

//#pragma pack(8)

//第一个属性开始， 从0开始偏移
//以后的每个结构体成员，放在  该类型大小 与 对齐模数 比取小的值的整数倍上面
//所有的属性都计算完后，在将整体做二次偏移， 放在结构体最大类型与对齐模数 比取小的值的整数倍上

typedef struct _STUDENT
{
    int a;     //0 ~ 3
    char b;     //4 ~ 7
    double c;   //8 ~ 15
    float d;    //16 ~ 24
}Student;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 16:14:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    printf("sizeof student = %d\n", sizeof(Student));
}


typedef struct _STUDENT2
{
    char a;    //0 ~ 7
    Student b; //8 ~ 31
    double c;   //32 ~ 39
}Student2;

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 16:14:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
    printf("sizeof student2 = %d\n", sizeof(Student2));
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-01 16:14:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    // printf("sizeof(double) %d\n", sizeof(double));
    // printf("sizeof(float) %d\n", sizeof(float));
    // printf("sizeof(long) %d\n", sizeof(long));

    test01();
    test02();

    return 0;
}
