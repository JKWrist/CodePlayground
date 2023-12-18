#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int ipv4_4byte_valid(char *addr, char *mask)
{
    if ((NULL == addr) || (NULL == mask))
    {
        printf("addr NULL\n");
        return 0;
    }

    printf("addr [%d.%d.%d.%d].\r\n", addr[0], addr[1], addr[2], addr[3]);

    char min_addr[4] = {0};
    char max_addr[4] = {0};
    for(int i = 0; i < 4; i++)
    {
        min_addr[i] = addr[i] & mask[i];
        max_addr[i] = addr[i] | (255 - mask[i]);
    }

    printf("min addr [%d.%d.%d.%d].\r\n", min_addr[0], min_addr[1], min_addr[2], min_addr[3]);
    printf("max addr [%d.%d.%d.%d].\r\n", max_addr[0], max_addr[1], max_addr[2], max_addr[3]);
    return 0;
}


int main()
{
	char ip[4] = {0};
    ip[0] = 192;
    ip[1] = 168;
    ip[2] = 10;
    ip[3] = 1;
	char mask[4] = {0};
    mask[0] = 255;
    mask[1] = 255;
    mask[2] = 255;
    mask[3] = 128;
	ipv4_4byte_valid(ip, mask);
	return 0;
}