#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int is_valid_ipv4(char *ip)
{
	int i;
	int a, b, c, d;
	char *endptr;

	// 将IP地址转换为整数
	endptr = NULL;
	a = strtol(ip, &endptr, 10);
	printf("111 %d\n", a);
	if (*endptr != '.')
	{
		return 0;
	}
	b = strtol(endptr + 1, &endptr, 10);
	printf("222 %d\n", b);
	if (*endptr != '.')
	{
		return 0;
	}
	c = strtol(endptr + 1, &endptr, 10);
	printf("333 %d\n", c);
	if (*endptr != '.')
	{
		return 0;
	}
	d = strtol(endptr + 1, &endptr, 10);
	printf("444 %d\n", d);
	if (*endptr != '\0')
	{
		return 0;
	}

	// 检查每个字节是否在0到255之间
	if (a < 0 || a > 255 || b < 0 || b > 255 || c < 0 || c > 255 || d < 0 || d > 255)
	{
		return 0;
	}

	// // 检查IP地址的每个字节之间是否用`.`分隔
	// if (endptr == ip || endptr[1] != '.' || endptr[3] != '.' || endptr[5] != '.')
	// {
	// 	return 0;
	// }

	return 1;
}

int main()
{
	char ip[] = "192.168.1.1";
	if (is_valid_ipv4(ip))
	{
		printf("%s is a valid IPv4 address.\n", ip);
	}
	else
	{
		printf("%s is not a valid IPv4 address.\n", ip);
	}
	return 0;
}