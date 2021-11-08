#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01()
{
    FILE *pfile = fopen("ip.txt", "r");
    char buf[1024] = {0};

    while (NULL != fgets(buf, 1024, pfile))
    {
        printf("%s", buf);
        if (strstr(buf, "nas0"))
        {
            for (int i = 0; i < 2; i++)
            {
                if (NULL != fgets(buf, 1024, pfile))
                {
                    continue;
                }
            }
            printf("nas0 111 %s", buf);
            if (strstr(buf, "fe80::1"))
            {
                printf("nas0 yes\n");
            }
        }
    }

    while (NULL != fgets(buf, 1024, pfile))
    {
        if (strstr(buf, "br0"))
        {
            printf("%s", buf);
            for (int i = 0; i < 2; i++)
            {
                if (NULL != fgets(buf, 1024, pfile))
                {
                    continue;
                }
            }
            printf("br0 111 %s", buf);
            if (strstr(buf, "fe80::1"))
            {
                printf("br0 yes\n");
            }
        }
    }
    fclose(pfile);
}

void test02()
{
    //cat /proc/net/if_inet6
    int iGetIPV6 = 0;
    FILE *pfile = fopen("ipv6.txt", "r");
    char buf[1024] = {0};

    while (NULL != fgets(buf, 1024, pfile))
    {
        printf("%s", buf);
        if (strstr(buf, "nas0"))
        {
            iGetIPV6 = 1;
            printf("br0 yes\n");
            break;
        }
    }
    fclose(pfile);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-08 11:20:21
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test01();

    test02();

    return 0;
}
