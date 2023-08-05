#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(char *p)
{
    strcpy(p, "hello worl");
}

void test01()
{
    //在test01中分配内存，分配在栈上
    char buf[1024] = {0};

    func(buf);

    printf("%s\n", buf);
}

void printString(char *str)
{
    printf("%s\n", str + 6);
}

void test02()
{
    //分配内存到堆上
    char *p = malloc(sizeof(char) * 64);
    memset(p, 0, 64);
    strcpy(p, "hello world");
    printString(p);

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}

void alloacateSpace(char **p)
{
    *p = malloc(sizeof(char) * 64);
    memset(*p, 0, 64);
    strcpy(*p, "hello world");
}

void test03()
{
    char *p = NULL;
    alloacateSpace(&p);

    printf("%s\n", p);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-05 23:29:00
*/
int main()
{
    test01();

    test02();
    test03();
    return 0;
}
