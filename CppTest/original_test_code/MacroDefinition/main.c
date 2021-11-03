#include <stdio.h>
#include <string.h>

//工作中见到了几种特殊的宏定义用法
//以下是测试用例

//1、error指令用于程序的调试, 当编译中遇到#error指令就停止编译。
//注意的是：报错信息不需要加引号" "，如果加上，引号会被一起输出
#error "error"

//2、pragma 编译指示
#pragma message("_X86 macro activated !")

//3、#的用法
#define STR(s) #s

//4、##的用法
#define CON1(a, b) a##e##b
#define CON2(a, b) a##b##00

//5、预定义宏
// ANSI C 规定了以下几个预定义宏，它们在各个编译器下都可以使用：
// __LINE__：表示当前源代码的行号；
// __FILE__：表示当前源文件的名称；
// __DATE__：表示当前的编译日期；
// __TIME__：表示当前的编译时间；
// __STDC__：当要求程序严格遵循ANSI C标准时该标识被赋值为1；
// __cplusplus：当编写C++程序时该标识符被定义。

//

void uart_printf(const char *fmt, ...);

#define MAX_MY_SPRINTF 500
char my_sprintf_buf[MAX_MY_SPRINTF];

#define PRINT(...) uart_printf(__VA_ARGS__)
#define FL_PRINT(...) uart_printf(__VA_ARGS__), uart_printf(",%s %d %s", __FILE__, __LINE__, __func__)
#define SPRINTF(buf, ...) sprintf(buf + strlen(buf), __VA_ARGS__), \
                          sprintf(buf + strlen(buf), ",%s %d %s", __FILE__, __LINE__, __func__), buf[MAX_MY_SPRINTF - 1] = 0

#define log(...) printf(__VA_ARGS__)

int main()
{
    log("1111\n");

    // SPRINTF("22222\n");
    // log("%s\n", my_sprintf_buf);

    printf(STR(222));

    printf("\n");

    printf("%f\n", 4.5e3);
    printf("%f\n", CON1(8.5, 2));
    printf("%d\n", CON2(12, 34));

    printf("Date : %s\n", __DATE__);
    printf("Time : %s\n", __TIME__);
    printf("File : %s\n", __FILE__);
    printf("Line : %d\n", __LINE__);

#if _WIN32
    printf("This is Windows!\n");
#elseif __linux__
    printf("This is Linux!\n");
#else
    printf("Unknown platform!\n");
#endif

#if __linux__
    printf("This is Linux!\n");
#endif

#if (defined NUM1 && defined NUM2)
    //代码A
    printf("NUM1: %d, NUM2: %d\n", NUM1, NUM2);
#else
    //代码B
    printf("NUM1  NUM2 not define\n");
#endif

    printf("\n");
    //fflush(stdin);
}
