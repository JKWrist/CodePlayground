#include <stdio.h>
#include <string.h>

struct Person
{
    int age;
    char name[20];
};
typedef struct Person Person;

typedef int *(*array_pointer_type)[10];

int *a[4][10];

int *(*p1)[10] = a;

array_pointer_type p2 = a;

array_pointer_type func(int len)
{
    printf("len = %d\n", len);
    return p2;
}

void test01()
{

    Person p1;
    p1.age=18;
    strcpy(p1.name, "xiaobai");

    printf("Hello World!\n");

    int *(*(*f)(int))[10] = func;
    func(100);
    f(200);
}

int array2[10];
int (*f2(int, int))[10];

int (*test02(int a, int b))[10]
{
    printf("%d %d\n", a, b);
    return &array2;
}

int (*(f3)[10])(int *);

int (*(*f4)(int, int))(int);

int (*f5(int *p, int, int(fd)(int *, int)));

int main()
{
    //test01();

    test02(3, 4);

    return 0;
}
