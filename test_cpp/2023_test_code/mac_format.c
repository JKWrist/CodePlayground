#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum
{
	MAC_TYPE_COLON, // 00:11:22:33:44:55
	MAC_TYPE_LINE,  // 00-11-22-33-44-55
	MAC_TYPE_NOTHING, // 001122334455
	MAC_TYPE_MAX,
} MAC_TYPE;

// 将 MAC 地址的字节形式转换为字符串形式
void convert_mac_bytes_to_string(char * mac_string, const char * mac_bytes, MAC_TYPE type)
{
	if ((NULL != mac_bytes) && (NULL != mac_string) && (type >= MAC_TYPE_MAX))
	{
		return;
	}
	
	if (MAC_TYPE_COLON == type)
	{
		sprintf(mac_string, "%02x:%02x:%02x:%02x:%02x:%02x", mac_bytes[0], mac_bytes[1], mac_bytes[2], mac_bytes[3], mac_bytes[4], mac_bytes[5]);
	}
	else if (MAC_TYPE_LINE == type)
	{
		sprintf(mac_string, "%02x-%02x-%02x-%02x-%02x-%02x", mac_bytes[0], mac_bytes[1], mac_bytes[2], mac_bytes[3], mac_bytes[4], mac_bytes[5]);
	}
	else if (MAC_TYPE_NOTHING == type)
	{
		sprintf(mac_string, "%02x%02x%02x%02x%02x%02x", mac_bytes[0], mac_bytes[1], mac_bytes[2], mac_bytes[3], mac_bytes[4], mac_bytes[5]);
	}
	else
	{
		printf("error type \n");
	}
	// 输出 MAC 地址的字符串形式
	printf("MAC address in string : %s\n", mac_string);
}

// 将 MAC 地址的字符串形式转换为字节形式
void convert_mac_string_to_bytes(char * mac_bytes, const char * mac_string, MAC_TYPE type)
{
	if ((NULL != mac_bytes) && (NULL != mac_string) && (type >= MAC_TYPE_MAX))
	{
		return;
	}
	
	if (MAC_TYPE_COLON == type)
	{
		sscanf(mac_string, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &mac_bytes[0], &mac_bytes[1], &mac_bytes[2], &mac_bytes[3], &mac_bytes[4], &mac_bytes[5]);
	}
	else if (MAC_TYPE_LINE == type)
	{
		sscanf(mac_string, "%hhx-%hhx-%hhx-%hhx-%hhx-%hhx", &mac_bytes[0], &mac_bytes[1], &mac_bytes[2], &mac_bytes[3], &mac_bytes[4], &mac_bytes[5]);
	}
	else if (MAC_TYPE_NOTHING == type)
	{
		for (int i = 0; i < 6; i++)
		{
			char byte_hex[3] = { mac_string[i * 2], mac_string[i * 2 + 1], '\0' };
			mac_bytes[i] = strtol(byte_hex, NULL, 16);
		}
	}
	else
	{
		printf("error type \n");
	}

	// 输出 MAC 地址的字节形式
	printf("MAC address in bytes : ");
	for (int i = 0; i < 6; i++)
	{
		printf("%02x ", mac_bytes[i]);
	}
	printf("\n");
}

void test01()
{
	// MAC地址的字符串形式
	char mac_address[] = "00:11:22:33:44:55";
	// MAC地址的字节形式
	unsigned char mac_bytes[6] = {0};
	convert_mac_string_to_bytes(mac_bytes, mac_address, MAC_TYPE_COLON);

	char mac_address_converted[18] = {0};
	convert_mac_bytes_to_string(mac_address_converted, mac_bytes, MAC_TYPE_COLON);
}

void test02()
{
	// MAC地址的字符串形式
	char mac_address[] = "00-11-22-33-44-55";
	// MAC地址的字节形式
	unsigned char mac_bytes[6] = {0};
	convert_mac_string_to_bytes(mac_bytes, mac_address, MAC_TYPE_LINE);

	char mac_address_converted[18] = {0};
	convert_mac_bytes_to_string(mac_address_converted, mac_bytes, MAC_TYPE_LINE);
}

void test03()
{
	// MAC地址的字符串形式
	char mac_address[] = "001122334455";
	// MAC地址的字节形式
	unsigned char mac_bytes[6] = {0};
	convert_mac_string_to_bytes(mac_bytes, mac_address, MAC_TYPE_NOTHING);

	char mac_address_converted[18] = {0};
	convert_mac_bytes_to_string(mac_address_converted, mac_bytes, MAC_TYPE_NOTHING);
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}