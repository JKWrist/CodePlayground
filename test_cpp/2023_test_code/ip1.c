#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_ip_class(const char *subnet)
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
			printf("1111\n");
            return 0;
        }
        subnet_addr |= octet << (24 - i * 8);
        subnet = end + 1;
    }

	printf("addr %08x \n", subnet_addr);
	printf("addr %08x \n", 0x80000000);
	printf("addr %08x \n", 0xC0000000);
	printf("addr %08x \n", 0xE0000000);

    // 判断 IP 地址类别    1000000000
    if ((subnet_addr & 0xffffff00) == 0xffffff00)
    {
        return 'A';
    }
    else if ((subnet_addr & 0xffff0000) == 0xffff0000)
    {
        return 'B';
    }
    else if ((subnet_addr & 0xff000000) == 0xff000000)
    {
        return 'C';
    }
    else
    {
		printf("22\n");
        return 0;
    }
}

int test(int argc, char *argv[])
{
    unsigned int my_ip;
    unsigned char first;
    my_ip = (inet_addr(argv[1]));
    first = (unsigned char )my_ip;
    if((first & 0x80) == 0)
    {
        printf("a\n");
    }
    if((first & 0xc0) == 0x80)
    {
        printf("b\n");
    }
    if((first & 0xe0) == 0xc0)
    {
        printf("c\n");
    }
    if((first & 0xf0) == 0xe0)
    {
        printf("d\n");
    }
    if((first & 0xf0) == 0xf0)
    {
        printf("e\n");
    }
    printf("%x\n", my_ip);
    return 0;
}

int main()
{
    const char *subnet = "192.168.252.1";
    char ip_class = get_ip_class(subnet);
    if (ip_class)
    {
        printf("子网掩码 %s 对应的 IP 地址类别为 %c\n", subnet, ip_class);
    }
    else
    {
        printf("无法判断子网掩码 %s 对应的 IP 地址类别\n", subnet);
    }
    return 0;
}



	/* see if our hostname corresponds to a reasonable IP address */
	hp = gethostbyname(hostname);
	if (hp != NULL) {
		addr = *(u_int32_t *)hp->h_addr;
		if (!bad_ip_adrs(addr)) {
			addr = ntohl(addr);
			if (!LOCAL_IP_ADDR(addr)) {
				ep->class = EPD_IP;
				set_ip_epdisc(ep, addr);
				return 1;
			}
		}
	}