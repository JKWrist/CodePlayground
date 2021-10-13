#include <stdio.h>
#include <string.h>
typedef union test_union
{
    char a;
    int b;
    double c;
    char str[32];
} test_union;

int main()
{
    test_union test1;
    test1.a='a';
    test1.b = 5;
    test1.c=5.6;
    strcpy(test1.str,"\\asdasd// ");//无需转义

    printf("test_union size %d\n\n", sizeof(test1));

    printf("%p %p %p %p\n", &test1.a, &test1.b , &test1.c, &test1.str[0]);
    printf("%c %d %lf %s\n\n", test1.a, test1.b , test1.c, test1.str);

    test1.b = 6;
    printf("%p %p %p %p\n", &test1.a, &test1.b , &test1.c, &test1.str[0]);
    printf("%c %d %lf %s\n\n", test1.a, test1.b , test1.c, test1.str);

    test1.c=7.8;
    printf("%p %p %p %p\n", &test1.a, &test1.b , &test1.c, &test1.str[0]);
    printf("%c %d %lf %s\n\n", test1.a, test1.b , test1.c, test1.str);
}