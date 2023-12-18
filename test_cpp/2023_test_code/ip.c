#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

int check_ip_subnet(const char *ip, const char *subnet)
{
    unsigned int ip_addr = 0, subnet_addr = 0;
    int i;

    // 解析 IP 地址
    for (i = 0; i < 4; i++)
    {
        char *end;
        unsigned int octet = strtoul(ip, &end, 10);
        if (end == ip || octet > 255)
        {
            return 0;
        }
        ip_addr |= octet << (24 - i * 8);
        ip = end + 1;
    }

    // 解析子网掩码
    for (i = 0; i < 4; i++)
    {
        char *end;
        unsigned int octet = strtoul(subnet, &end, 10);
        if (end == subnet || octet > 255)
        {
            return 0;
        }
        subnet_addr |= octet << (24 - i * 8);
        subnet = end + 1;
    }

    // 检查是否匹配
    return (ip_addr & subnet_addr) == subnet_addr;
}

void test1()
{
    const char *ip = "192.168.1.100";
    const char *subnet = "255.255.255.0";
    if (check_ip_subnet(ip, subnet))
    {
        printf("IP 地址 %s 匹配子网掩码 %s\n", ip, subnet);
    }
    else
    {
        printf("IP 地址 %s 不匹配子网掩码 %s\n", ip, subnet);
    }
}

void get_min_max_ip(const char *ip, const char *subnet, char *min_ip, char *max_ip)
{
    unsigned int subnet_addr = 0;
    int i;

    // 解析子网掩码
    for (i = 0; i < 4; i++)
    {
        char *end;
        unsigned int octet = strtoul(subnet, &end, 10);
        if (end == subnet || octet > 255)
        {
            return;
        }
        subnet_addr |= octet << (24 - i * 8);
        subnet = end + 1;
    }

    // 计算最小 IP 地址
    unsigned int min_addr = (subnet_addr & 0xFFFFFF00) + 1;
    sprintf(min_ip, "%d.%d.%d.%d",
            (min_addr >> 24) & 0xFF,
            (min_addr >> 16) & 0xFF,
            (min_addr >> 8) & 0xFF,
            min_addr & 0xFF);

    // 计算最大 IP 地址
    unsigned int max_addr = (subnet_addr | 0x000000FF) - 1;
    sprintf(max_ip, "%d.%d.%d.%d",
            (max_addr >> 24) & 0xFF,
            (max_addr >> 16) & 0xFF,
            (max_addr >> 8) & 0xFF,
            max_addr & 0xFF);
}


void test3()
{
    const char *ip_address = "192.168.1.1";
    uint32_t ip = inet_addr(ip_address);

    printf("IP地址的四个字节: %hhu.%hhu.%hhu.%hhu\n",
           (ip >> 0) & 0xff, (ip >> 8) & 0xff,
           (ip >> 16) & 0xff, (ip >> 24) & 0xff);

}

int main()
{
	// test1();
	// test2();
    test3();

    return 0;
}
