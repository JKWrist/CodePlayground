#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#define INET6_ADDRSTRLEN 46

typedef enum
{
    IPV6_NONE = 0,
    IPV6_LINKLOCAL = 1,
    IPV6_GLOBAL = 2
} IPV6_ADDRESS_T;

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

char getIpv6AddrByIfname(char *ifname, int addrtype, char *addr, int *plen)
{
    int if_index = 0, prefix_len = 0, if_scope = 0, if_flag = 0, ret = 0, i = 0;
    char devname[32] = {0}, ipv6[INET6_ADDRSTRLEN] = {0};
    struct sockaddr_in6 addr6;
    FILE *fp = NULL;
    fp = fopen("ipv6.txt", "r");
    if (fp != NULL)
    {
        while ((ret = fscanf(fp, "%s %x %x %x %x %s", ipv6, &if_index, &prefix_len, &if_scope, &if_flag, devname)) != EOF)
        {
            //printf("%s %x %x %x %x %s\n", ipv6, if_index, prefix_len, if_scope, if_flag, devname);

            if (ret != 6)
            {
                continue;
            }
            /*interface match?*/
            if (strcmp(ifname, devname) == 0)
            {
                ret = sscanf(ipv6, "%04hx%04hx%04hx%04hx%04hx%04hx%04hx%04hx",
                             &addr6.sin6_addr.s6_addr[0], &addr6.sin6_addr.s6_addr[1], &addr6.sin6_addr.s6_addr[2], &addr6.sin6_addr.s6_addr[3],
                             &addr6.sin6_addr.s6_addr[4], &addr6.sin6_addr.s6_addr[5], &addr6.sin6_addr.s6_addr[6], &addr6.sin6_addr.s6_addr[7]);

                for (i = 0; i < 8; i++)
                {
                    addr6.sin6_addr.s6_addr[i] = htons(addr6.sin6_addr.s6_addr[i]);
                }

                // memcpy(addr6.sin6_addr.s6_addr, ipv6, sizeof(addr6.sin6_addr.s6_addr));

                printf("111 %#X\n", addr6.sin6_addr.s6_addr);
                printf("222 %#X\n", addr6.sin6_addr.s6_addr[0]);
                printf("333 %#X\n", 0xFE80);
                printf("444 %#X\n", htons(0xFE80));

                switch (addrtype)
                {
                case IPV6_GLOBAL:
                    if (addr6.sin6_addr.s6_addr[0] != htons(0xFE80) && addr6.sin6_addr.s6_addr[0] != 0000)
                    {
                        inet_ntop(AF_INET6, &addr6, addr, INET6_ADDRSTRLEN);
                        *plen = prefix_len;
                        fclose(fp);
                        return 1;
                    }
                    break;
                case IPV6_LINKLOCAL:
                    if (addr6.sin6_addr.s6_addr[0] == ntohs(0xFE80))
                    {
                        inet_ntop(AF_INET6, &addr6, addr, INET6_ADDRSTRLEN);
                        *plen = prefix_len;
                        fclose(fp);
                        return 1;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        fclose(fp);
        return 0;
    }
    return 0;
}

static int isGet_ipv6_ip()
{
    unsigned char opMode = 0;
    char lan_ifname[32] = "br0";
    char wan_ifname[32] = "nas0";
    char ppp_ifname[32] = "ppp0";
    char ipv6_addr_str[64] = {0};
    int global_addr_prefix_len = 0;

    // if (opMode == BRIDGE_MODE)
    if (!getIpv6AddrByIfname(lan_ifname, IPV6_GLOBAL, ipv6_addr_str, &global_addr_prefix_len))
        printf("ERROR (%s)%d get lan ipv6 global addr fail\n", __FUNCTION__, __LINE__);
    else
        printf("%s, %s, %d\n", lan_ifname, ipv6_addr_str, global_addr_prefix_len);



    // else if ((opMode == GATEWAY_MODE) && (wanEntry.cmode == CHANNEL_MODE_PPPOE))
    if (!getIpv6AddrByIfname(ppp_ifname, IPV6_GLOBAL, ipv6_addr_str, &global_addr_prefix_len))
        printf("ERROR (%s)%d get ppp ipv6 global addr fail\n", __FUNCTION__, __LINE__);
    else
        printf("%s, %s, %d\n", ppp_ifname, ipv6_addr_str, global_addr_prefix_len);



    // else if ((opMode == GATEWAY_MODE) && (wanEntry.AddrMode != IPV6_WAN_STATIC))
    if (!getIpv6AddrByIfname(wan_ifname, IPV6_GLOBAL, ipv6_addr_str, &global_addr_prefix_len))
        printf("ERROR (%s)%d get wan ipv6 global addr fail\n", __FUNCTION__, __LINE__);
    else
        printf("%s, %s, %d\n", wan_ifname, ipv6_addr_str, global_addr_prefix_len);
}

void test03()
{
    isGet_ipv6_ip();
}

void test04()
{
    int i = 47;
    printf("%x\n", i);
    printf("%X\n", i);
    printf("%#x\n", i);
    printf("%#X\n", i);
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

    //test02();

    test03();

    //test04();

    return 0;
}
