#include <stdio.h>
#include <stdarg.h>

/****************************************************************
 *  函数名称：va_list, va_start(fmt,args), va_end(args)
 *  创建日期：2022-02-07 15:51:44
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void  test01(char *fmt,...)
{
	printf("start function :%s\n\n", __FUNCTION__);

    va_list args;
    va_start(args,fmt);
    vprintf(fmt, args);
    va_end(args);
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：__attribute__((format(printf,1,2)))
 *  创建日期：2022-02-07 15:52:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void __attribute__((format(printf,1,2))) test02(char *fmt,...)
{
	printf("start function :%s\n\n", __FUNCTION__);
    va_list args;
    va_start(args,fmt);
    vprintf(fmt, args);
    va_end(args);
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：实现自己的日志打印函数 1
 *  创建日期：2022-02-07 16:13:57
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define DEBUG //打印开关
void __attribute__((format(printf, 1, 2))) LOG(char *fmt, ...)
{
#ifdef DEBUG
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
	printf("---------------------------\n");
#endif
}


/****************************************************************
 *  函数名称：实现自己的日志打印函数 2
 *  创建日期：2022-02-07 16:25:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int debugLevel = 1;
#define DEBUG_PRINT(fmt, args...) \
	do { \
		if (debugLevel >= 1) { \
			printf("%s(%d):" fmt, __FUNCTION__, __LINE__, ##args); \
		} \
	} while(0)


/****************************************************************
 *  函数名称：实现自己的日志打印函数 3 日志等级
 *  创建日期：2022-02-07 16:25:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define debug(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <debug>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define info(fmt, ...) ({\
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <info>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define notice(fmt, ...) ({ \
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <notice>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define warn(fmt, ...) ({ \
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <warn>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})
#define error(fmt, ...) ({ \
    time_t t; \
    time(&t); \
    struct tm * tmt = localtime(&t); \
    printf("%02d:%02d:%02d <error>: "     fmt "\n", \
        tmt->tm_hour, tmt->tm_min, tmt->tm_sec, ##__VA_ARGS__); \
})


int main(void)
{
    int num = 1;
    test01("I am %s, I have %d dream\n", "小红", num);

	test02("I am %s, I have %d dream\n", "小白", num);

	LOG("I am %s, I have %d dream\n", "小绿", num);

    return 0;
}
