#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、%*s 或 %*d 跳过数据
void test01()
{
    char *str1 = "12345abcde";
    char *str2 = "abcde12378";

    char buf[1024] = {0};
    sscanf(str1, "%*d%s", buf);
    printf("test01 %s\n", buf);

    int num;
    sscanf(str2, "%*s%d", &num); //这里是判断不出来的，因为将整个作为字符串了
    printf("test01 num %d\n", num);
}

void test02()
{
    //忽略遇到空格或者\t代表结束
    char *str1 = "abcde12345";
    char *str2 = "abcde123 45";
    char *str3 = "abcde123\t45";

    char buf[1024] = {0};
    sscanf(str1, "%*[a-z]%s", buf);
    printf("test02 %s\n", buf);

    memset(buf, 0, 1024);
    sscanf(str2, "%*[a-z]%s", buf);
    printf("test02 %s\n", buf);

    memset(buf, 0, 1024);
    sscanf(str3, "%*[a-z]%s", buf);
    printf("test02 %s\n", buf);
}

//%[width]s   读取指定宽度额数据
void test03()
{
    char *str = "12345abcde";
    char buf[1024] = {0};

    sscanf(str, "%6s", buf);

    printf("test03 %s\n", buf);
}

//%[a-z] 匹配a到z中的任意字符（尽可能多的匹配）
void test04()
{
    char *str = "0123456abcdefg";
    char buf[1024] = {0};
    sscanf(str, "%*d%s", buf);
    printf("test04 %s\n", buf);
}

void test05()
{
    char *str = "12345abcdefg";
    char buf[1024] = {0};

    sscanf(str, "%[0-9]", buf); //这里不需要写%s了，匹配失败就不继续匹配了
    printf("test05 %s\n", buf);
}

void test06()
{
    char *str = "aBcdefg";

    char buf[1024] = {0};
    sscanf(str, "%[aBc]", buf);
    printf("test06 %s\n", buf);
}

//%[^a]   匹配非a的任意字符，贪婪性
void test07()
{
    char *str = "abCdef";
    char buf[1024] = {0};
    sscanf(str, "%[^C]", buf);
    printf("test07 buf %s\n", buf);
}


//%[^a-z] 表示读取除a-z之外的所有字符
void test08()
{
    char * str = "asdasdlkj1231289";
    char buf[1024] = {0};
    sscanf(str, "%[^0-9]", buf);
    printf("test08 buf %s\n", buf);
}

void test09()
{
    char * str = "127.0.0.1";
    int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
    int ret = sscanf(str, "%d.%d.%d.%d", &num1, &num2, &num3, &num4);
    printf("%d - %d.%d.%d.%d\n", ret, num1, num2, num3, num4);
}

//2030.9.1#jkwrist@192.168.0.1   //过滤出名称来
void test10()
{
    char *str = "2030.9.1#jkwrist@192.168.0.1";
    char buf[1024] = {0};
    sscanf(str, "%*[^#]#%[^@]", buf);
    printf("test10 buf %s\n", buf);
}

//1.已给定字符串为: helloworld@163.com,
//请编码实现helloworld输出和163.com输出。
void test11()
{
    char *str = "helloworld@163.com";
    char buf[1024] = {0};
    sscanf(str, "%[^@]", buf);
    printf("buf %s\n", buf);

    memset(buf, 0, 1024);
    sscanf(str, "%*[^@]@%s", buf);
    printf("buf %s\n", buf);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-07 18:30:20
*/
int main()
{
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test06();

    //test07();

    //test08();

    //test09();

    //test10();

    test11();
    
    return 0;
}
