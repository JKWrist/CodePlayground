#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、void无类型，不可以通过void创建变量，原因无法给void类型变量分配内存
void test1()
{
    //void a = 10;
}

//2、限定函数返回值类型
void test2(void)
{
    //return 10;
}

//3、void * 万能指针
//不管几级指针，32位系统  任意类型指针都是4字节
//             64位系统  任意类型指针都是8字节
void test3()
{
    printf("the size of void * %d\n", sizeof(void *));
    void * pVoid = NULL;

    int * pInt = NULL;
    char * pChar = NULL;
    pVoid = pChar;

    //incompatible pointer types assigning to 'char *' from 'int *'
    pChar = pInt; 
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 10:14:55
*/
int main()
{
    test1();
    test2();
    test3();


    return 0;
}
