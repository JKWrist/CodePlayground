#include <stdio.h>

#define MAC_ADDRESS_LEN 6

char mac_str[20] = "0e:bc:32:78:ee:23";//0e:bc:32:78:ee:23
char mac_str_tmp[10] = {0};

/****************************************************************
 *  函数名称：正确地址转换
 *  创建日期：2022-03-30 19:49:22
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
static int parse_mac_1(const char *mac_str, char *buf)
{
	int mac_int[6];
	int t = sscanf(mac_str, "%02x:%02x:%02x:%02x:%02x:%02x",
				&mac_int[0], &mac_int[1], &mac_int[2], &mac_int[3], &mac_int[4], &mac_int[5]);

	printf("t %d\n", t);

	int i;
	for(i=0; i<10; i++)
	{
		buf[i] = mac_int[i];
		printf("mac_int[%d] %d\n", i, mac_int[i]);
		printf("mac_int[%d] %02x\n", i, mac_int[i]);
	}

	if (t != MAC_ADDRESS_LEN)
	{
		return -1;
	}
	return 0;
}

/****************************************************************
 *  函数名称：存在问题
 *  创建日期：2022-03-30 19:49:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
static int parse_mac_2(const char *mac_str, char *buf)
{
	int t = sscanf(mac_str, "%02x:%02x:%02x:%02x:%02x:%02x",
				&buf[0], &buf[1], &buf[2], &buf[3], &buf[4], &buf[5]);

	int i;
	for(i=0; i<10; i++)
	{
		printf("buf[%d] %d\n", i, buf[i]);
		printf("buf[%d] %02x\n", i, buf[i]);
	}

	if (t != MAC_ADDRESS_LEN)
			return -1;

	return 0;
}

void test01()
{
	printf("\n%s \n", __FUNCTION__);
	parse_mac_1(mac_str, mac_str_tmp);
	printf("mac_str %s\n", mac_str);
	printf("mac_str_tmp %s\n", mac_str_tmp);
}

void test02()
{
	printf("\n%s \n", __FUNCTION__);
	parse_mac_2(mac_str, mac_str_tmp);
	printf("mac_str %s\n", mac_str);
	printf("mac_str_tmp %s\n", mac_str_tmp);
}

void test03()
{
	printf("\n%s \n", __FUNCTION__);

	char mac_int[6] = "123456";
	int t = printf("%02x:%02x:%02x:%02x:%02x:%02x",
				mac_int[0], mac_int[1], mac_int[2], mac_int[3], mac_int[4], mac_int[5]);

	printf("t %d\n", t);
}

int main()
{
	test01();
	test02();
	test03();

	return 0;
}