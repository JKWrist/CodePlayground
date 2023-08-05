#include <stdio.h>
#include <time.h>
#include <dirent.h>
#include <sys/time.h>
#include <sys/types.h>


int kMicroSecondsPerSecond = 1000 * 1000;
int64_t NMicroSecondsPerSecond = 1000 * 1000 * 1000;


void test01()
{
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);
    printf("CLOCK_REALTIME: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    //打印出来的时间跟 cat /proc/uptime 第一个参数一样
    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("CLOCK_MONOTONIC: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    printf("CLOCK_PROCESS_CPUTIME_ID: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts);
    printf("CLOCK_THREAD_CPUTIME_ID: %d, %d\n", ts.tv_sec, ts.tv_nsec);

    printf("/n%d/n", time(NULL));
}

int64_t now1()
{
    struct timeval tv;
    //gettimeofday就是clock_gettime（CLOCK_MONOTONIC）的用户层封装，并且降低了clock_gettime函数的精度，
    //clock_gettime能精确到纳秒级，而gettimeofday精确到微妙级
    gettimeofday(&tv, NULL); 
    int64_t seconds = tv.tv_sec;
    printf("gettimeofday %ld\n", seconds);
    return seconds * kMicroSecondsPerSecond + tv.tv_usec;
    //返回一个Timestamp结构体，相当于创建一个当前时间的Timestamp结构体
}

int64_t now2()
{
    struct timespec tv;
    //gettimeofday就是clock_gettime（CLOCK_MONOTONIC）的用户层封装，并且降低了clock_gettime函数的精度，
    //clock_gettime能精确到纳秒级，而gettimeofday精确到微妙级
    clock_gettime(CLOCK_MONOTONIC, &tv); 
    int64_t seconds = tv.tv_sec;
    printf("clock_gettime %ld\n", seconds);
    return seconds * kMicroSecondsPerSecond + tv.tv_nsec / 1000;
    //返回一个Timestamp结构体，相当于创建一个当前时间的Timestamp结构体
}

void translate(int64_t microSecondsSinceEpoch_)
{
    char buf[32] = {0};
    time_t seconds = (time_t)(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
    int microseconds = (int)(microSecondsSinceEpoch_ % kMicroSecondsPerSecond);
    struct tm tm_time;
    gmtime_r(&seconds, &tm_time); //将总秒数转换成————年-月-日-小时-分-秒为单位，并且还会自动加上1970年1月1日时间
    snprintf(buf, sizeof(buf), "%4d-%02d-%02d %02d:%02d:%02d.%06d",
             tm_time.tm_year + 1900, tm_time.tm_mon + 1, tm_time.tm_mday,
             tm_time.tm_hour, tm_time.tm_min, tm_time.tm_sec,
             microseconds); //总秒数加上1900年1月1日然后转换成固定格式
    printf("%s\n", buf);
}


void test02()
{
    int64_t microSecondsSinceEpoch1_ = now1();
    translate(microSecondsSinceEpoch1_);

    int64_t microSecondsSinceEpoch2_ = now2();
    translate(microSecondsSinceEpoch2_);

    translate(0);
}

/****************************************************************
 *  函数名称：time / ctime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
    time_t timep;
    time(&timep); /*获取time_t类型当前时间*/
    /*转换为常见的字符串：Fri Jan 11 17:04:08 2008*/
    printf("%s", ctime(&timep));
}

/****************************************************************
 *  函数名称：time / asctime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test04()
{
    time_t timep;
    time(&timep); /*获取time_t类型当前时间*/
    /*用gmtime将time_t类型的时间转换为struct tm类型的时间按，
    //没有经过时区转换的UTC时间
    然后再用asctime转换为我们常见的格式 Fri Jan 11 17:25:24 2008
    */
    printf("%s", asctime(gmtime(&timep)));
}

/****************************************************************
 *  函数名称：time / gmtime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test05()
{
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;

    time(&timep);       /*获得time_t结构的时间，UTC时间*/
    p = gmtime(&timep); /*转换为struct tm结构的UTC时间*/
    printf("%d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("%s %d:%d:%d\n", wday[p->tm_wday], p->tm_hour,
           p->tm_min, p->tm_sec);
}

/****************************************************************
 *  函数名称：time / localtime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test06()
{
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t timep;
    struct tm *p;

    time(&timep);          /*获得time_t结构的时间，UTC时间*/
    p = localtime(&timep); /*转换为struct tm结构的当地时间*/
    printf("%d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("%s %d:%d:%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
}

/****************************************************************
 *  函数名称：time / localtime / mktime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test07()
{
    time_t timep;
    struct tm *p;

    time(&timep); /*当前time_t类型UTC时间*/
    printf("time():%d\n", timep);

    /*转换为本地的tm结构的时间按*/
    /*重新转换为time_t类型的UTC时间，这里有一个时区的转换*/
    p = localtime(&timep);
    //by lizp 错误，没有时区转换， 将struct tm 结构的时间转换为从1970年至p的秒数
    timep = mktime(p); 
    
    printf("time()->localtime()->mktime(): %d\n", timep);
}

/****************************************************************
 *  函数名称：time / gmtime /mktime
 *  创建日期：2021-12-23 20:29:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test08()
{
    time_t timep;
    struct tm *p;

    time(&timep); /*得到time_t类型的UTC时间*/
    printf("time():%d\n", timep);
    /*得到tm结构的UTC时间*/
    p = gmtime(&timep);
    //没有时区转换， 将struct tm 结构的时间转换为从1970年至p的秒数
    timep = mktime(p); 

    printf("time()->gmtime()->mktime(): %d\n", timep);
}

int main()
{
    //test01();

    //test02();

    //test03();

    //test04();

    //test05();

    //test06();

    test07();

    test08();

    return 0;
}