#include <time.h>
#include <stdio.h>

void test01()
{
    struct tm *ptr;
    time_t tmpTime;

    tmpTime = time(NULL);
    tmpTime -= 3600;
    ptr = gmtime(&tmpTime);

    printf("year-mon-mday %d-%d-%d\n", ptr->tm_year + 1900, ptr->tm_mon + 1, ptr->tm_mday);
    printf("hour:min:sec %d:%d:%d\n", ptr->tm_hour, ptr->tm_min, ptr->tm_sec);

    printf("isdst %d\n", ptr->tm_isdst);

    printf(asctime(ptr));
    printf(ctime(&tmpTime));

    char tmpbuf[128];
    ptr = localtime(&tmpTime);
    strftime(tmpbuf, 128, "Today is %A, day %d of %B in the year %Y.\n", ptr);
    printf(tmpbuf);
}

void test02()
{
    //一天，一小时，一分钟，一秒
    int iTime = 3600 * 24 + 3600 * 2 + 60 + 1;
    printf("iTime %d\n", iTime);
    int iDay = 0, iHour = 0, iMin = 0, iSec = 0;

    iDay    = iTime / 3600 / 24;
    iHour   = (iTime - (iTime / 3600 / 24) * 3600 * 24) / 3600;
    iMin    = (iTime - (iTime / 3600) * 3600) / 60;
    iSec    = iTime % 60;

    printf("day %d \nhour %d \nmin %d \nsec %d \n", iDay, iHour, iMin, iSec);
}

void test03()
{
    char ts[1024] = {0};
    time_t nowtime;
    struct tm *tm_nowtime = NULL;

    nowtime = time(NULL);
    tm_nowtime = localtime(&nowtime);
    //strftime(ts, 1024, "%Y%m%dT%H%M%SZ", tm_nowtime);

    strftime(ts, 1024, "%F %T", tm_nowtime);

    printf("%s\n", ts);
}

int main(void)
{
    //test01();

    //test02();

    test03();

    return 0;
}