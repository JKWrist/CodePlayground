#include <stdio.h>

#define LOG_1(fmt, ...) printf(fmt, __VA_ARGS__)
#define DEBUG(...) printf(__VA_ARGS__)

/****************************************************************
 *  函数名称：
 *  创建日期：2022-02-08 16:18:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	LOG_1("Hello I'm : %s\n", "小白");
	DEBUG("Hello I'm : %s\n", "小红");
	DEBUG("Hello I'm \n");
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-02-08 16:18:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	//LOG_1("hello1\n");
}

/****************************************************************
 *  函数名称：宏连接符##
 *  创建日期：2022-02-08 16:24:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define A(x) a##x
void test03()
{
	int A(1) = 1; // int a1 = 1
	int A() = 3;  // int a  = 3

	printf("a1 = %d a = %d\n", a1, a);
}


/****************************************************************
 *  函数名称：可变参数宏的改进版
 *  创建日期：2022-02-08 16:33:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define LOG_2(fmt, ...) printf(fmt, ##__VA_ARGS__)
//#define DEBUG2(...) printf(__VA_ARGS__##)
void test04()
{
	LOG_2("hello2\n");
//	DEBUG2();
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-02-08 16:34:13
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define LOG_3(fmt, args...) printf(fmt, ##args)

void test05()
{
	LOG_3("hello3\n");
}


/****************************************************************
 *  函数名称：内核中的可变参数宏
 *  创建日期：2022-02-08 16:41:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#if defined(CONFIG_DYNAMIC_DEBUG)
#define pr_debug(fmt, ...) \
    dynamic_pr_debug(fmt, ##__VA_ARGS__)
#elif defined(DEBUG)
#define pr_debug(fmt, ...) \
    printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)
#else
#define pr_debug(fmt, ...) \
    no_printk(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)
#endif

#define dynamic_pr_debug(fmt, ...)                \
do {                                \
    DEFINE_DYNAMIC_DEBUG_METADATA(descriptor, fmt); \
    if (unlikely(descriptor.flags       \
            & _DPRINTK_FLAGS_PRINT))    \
        __dynamic_pr_debug(&descriptor, pr_fmt(fmt),    \
                   ##__VA_ARGS__);      \
} while (0)

// static inline __printf(1, 2)
// int no_printk(const char *fmt, ...)
// {
//     return 0;
// }

// #define __printf(a, b)      
// __attribute__((format(printf, a, b)))


int main()
{
	test01();
	test02();
	test03();

	test04();
	test05();
	return 0;
}