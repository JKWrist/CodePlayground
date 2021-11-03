#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>


#ifdef DEBUG
#define ASSERT(condition)               \
    do                                  \
    {                                   \
        if (condition)                  \
            NULL;                       \
        else                            \
            Assert(__FILE__, __LINE__); \
    } while (0)
#else
#define ASSERT(condition) NULL
#endif

void Assert(char * filename, unsigned int line)
{
    printf("Assert\n");

    fflush(stdout);
    fprintf(stderr, "\nAssert failed: %s, line %u\n", filename, line);
    fflush(stderr);
    abort();
}

void test01(unsigned char * str)
{
    ASSERT(str != NULL);
}

void test02(unsigned char *str)
{
    /*函数处理代码*/
    assert(str != NULL);

}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-29 15:28:29
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    // 编译方法
    // gcc assert_test.c -D DEBUG

    //test01(NULL);

    test02(NULL);

    return 0;
}
