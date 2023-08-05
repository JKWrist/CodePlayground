#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01()
{
    //字符串结束位置\0
    char str1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    printf("str1 %s\n", str1);

    char str2[100] = {'h', 'e', 'l', 'l', 'o'};
    printf("str2 %s\n", str2);

    char str3[] = "hello world";
    printf("sizeof str:%d\n", sizeof(str3)); //6
    printf("strlen str:%d\n", strlen(str3)); //5

    char str4[100] = "hello world";
    printf("sizeof str:%d\n", sizeof(str4));
    printf("strlen str:%d\n", strlen(str4));
}
//--------------------------------------------------------
//实现字符串拷贝
//1、利用[]实现
char *mystrcpy1(char *dst, char *src)
{
    int i = 0, j = 0;
    while (src[i] != '\0')
    {
        dst[j++] = src[i++];
    }
    dst[j] = '\0';

    return dst;
}

////2.1、利用指针实现, 2.2、利用指针实现为什么没有实现功能
//dst指针一直往前偏移，找一个临时指针向前偏移就好

//2.1、利用指针实现
char *error_mystrcpy2(char *dst, char *src)
{
    while (*src != '\0')
    {
        //*dst++ = *src++;

        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    printf("%s\n", dst);
    return dst;
}

//2.2、利用指针实现
char *error_mystrcpy3(char *dst, char *src)
{
    while (*dst++ = *src++)
    {
    };

    return dst;
}

//2、利用字符串指针
void copyString02(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;

        dest++;
        src++;
    }
    *dest = '\0';
}

//3
void copyString03(char *dest, char *src)
{
    while (*dest++ = *src++)
    {
    }
}

//2.1、利用指针实现
char *right_mystrcpy2(char *dst, char *src)
{
    char *tmp = dst;
    while (*src != '\0')
    {
        *tmp++ = *src++;
    }
    *tmp = '\0';
    return dst;
}

//2.2、利用指针实现
char *right_mystrcpy3(char *dst, char *src)
{
    char *tmp = dst;
    while (*tmp++ = *src++)
    {
    };

    return dst;
}

void test02()
{
    char buf[1024] = {0};
    char *str = "hello world";
    memset(buf, 0, 1024);
    printf("mystrcpy1 %s\n", mystrcpy1(buf, str));

    memset(buf, 0, 1024);
    printf("mystrcpy2 %s\n", right_mystrcpy2(buf, str));

    memset(buf, 0, 1024);
    printf("mystrcpy3 %s\n", right_mystrcpy3(buf, str));

    memset(buf, 0, 1024);
    copyString02(buf, str);
    printf("copyString02 %s\n", buf);

    memset(buf, 0, 1024);
    copyString03(buf, str);
    printf("copyString03 %s\n", buf);
}

//--------------------------------------------------------

//字符串反转
//[]
char *reverseString01(char *src)
{
    int i = 0, j = strlen(src) - 1;   //这里要减一,10个字符的字符数组，最后一个字符下表是9

    char tmp;
    while(i < j)
    {
        tmp = src[i];
        src[i] = src[j];
        src[j] = tmp;

        i++;
        j--;
    }
    return src;
}

//*
char *reverseString02(char *src)
{
    //这里要减一,10个字符的字符数组，最后一个字符下表是9
    char *start = src, *end = src + strlen(src) - 1;
    char tmp;

    while (start < end)
    {
        tmp = *start;
        *start = *end;
        *end = tmp;

        start++;
        end--;
    }

    return src;
}

void test03()
{

    char buf1[1024] = "hello world";

    char buf2[1024] = "hello world";

    printf("%s\n", reverseString01(buf1));

    printf("%s\n", reverseString02(buf2));
}

/*
* Author:xujunze
* Description: 所有练习务必落实到代码上，一方面是锻炼打字速度，
               另一方面是因为只有自己写才会发现错误， 目前的阶段多写，多调试
* Date: Create in 2021-09-07 15:03:11
*/
int main()
{
    //test01();

    //test02();

    test03();

    return 0;
}
