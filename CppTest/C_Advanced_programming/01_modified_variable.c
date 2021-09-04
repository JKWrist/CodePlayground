#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//变量的修改方式
void test01()
{
    int a = 10;

    //直接修改
    a = 20;
    printf("a = %d\n", a);
    
    //间接修改
    int * p = &a;
    *p = 30;
    printf("a = %d\n", a);
}

struct Person
{
    char a; //0-3
    int b;  //4-7
    char c; //8-11
    int d;  //12-15
};

void test02()
{
    struct Person p1 = {'a', 10, 'b', 20};
    //直接修改
    p1.a = 'b';
    printf("struct Person size %d\n", sizeof(p1));

    //间接修改
    struct Person *pPerson = &p1;
    pPerson->d = 80;
    printf("struct Person %d\n", pPerson->d);

    char *p = (char *)&p1;
    *(int *)(p + 12) = 2000;

    printf("d 的属性 %d\n", *(int *)(p + 12));
    printf("d 的属性 %d\n", *(int *)((int *)p + 3));
}


/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 11:06:03
*/
int main()
{
    test01();
    test02();
    
    return 0;
}
