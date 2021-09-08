#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//calloc
void test01()
{
    //Apple clang version 12.0.0 (clang-1200.0.32.29) 把数据清零了,其他编译器暂不确定
    //int * p = (int *)malloc(10 * sizeof(int));

    int *p = (int *)calloc(p, sizeof(int) * 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

//realloc 重新分配内存
void test02()
{
    int *p = malloc(sizeof(int) * 10);
    for (int i = 0; i < 10; i++)
    {
        p[i] = i + 100;
    }
    printf("malloc %p\n", p);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", p[i]);
    }

    //重新分配内存, 不同编译器实现不同，Apple clang version 12.0.0将重新分配内存也清空了
    p = realloc(p, 20 * sizeof(int));

    printf("realloc %p\n", p);
    for (int i = 0; i < 20; i++)
    {
        printf("%d\n", p[i]);
    }
    
    
    //重新分配内存比原来小，那么释放后续空间，只有权限操作申请空间
    p = realloc(p, 4 * sizeof(int));
    printf("%d\n", p[0]);
    printf("%d\n", p[10]); //此处同样是有风险的，clang虽然可以不代表其他的也可以
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-07 17:38:44
*/
int main()
{
    //test01();

    test02();

    return 0;
}
