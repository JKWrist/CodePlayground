#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *getSpace()
{
    int *p = malloc(sizeof(int) * 5);
    if (p == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < 5; i++)
    {
        p[i] = i + 100;
    }
    return p;
}

void test01()
{
    int *p = getSpace();
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", p[i]);
    }

    free(p);
    p = NULL;
}

void strncpy_test()
{
    char dest[20];   //此处故意不做初始化
    char src[] = "hello world";

    strncpy(dest, src, 5);  //长度小于需要拷贝的串的时候会拷贝到'\0'
    printf("111 %s\n", dest);

    dest[5] = '\0'; //会拷贝到结尾'\0'
    printf("222 %s\n", dest);
}

void strcpy_test()
{
    char dest[20] = "123456789";
    char src[] = "hello world";
    strcpy(dest, src);   //会拷贝'\0'
    printf("%s\n", dest);
}

void allocateSpace(char * pp)
{
    char * pTemp = malloc(100);
    memset(pTemp, 0, 100);
    strcpy(pTemp, "HELLO WORLD");
    pp = pTemp;
}

void test02()
{
    char * p = NULL;
    allocateSpace(p);
    printf("%s\n", p);
}

//为什么此处传二级指针 就是传值与传地址
//传递指针本身只是一个临时拷贝变量，但是传地址可以
//从地址找到数据位置进行赋值
void allocateSpace2(char **pp)
{
    char *pTemp = malloc(100);
    memset(pTemp, 0, 100);
    strcpy(pTemp, "HELLO WORLD");
    *pp = pTemp;
}

void test03()
{
    char * p = NULL;
    allocateSpace2(&p);
    printf("%s\n", p);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 14:20:36
*/
int main()
{
    // test01();
    // strcpy_test();
    // strncpy_test();

    test02();

    test03();
    return 0;
}
