#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char *argv[]) 
{
	int i = 12;
	printf("%x\n", i);
	printf("%X\n", i);
	printf("%02X\n", i);
	printf("%02x\n", i);
	printf("%x\n", 1 << 4);
	printf("%d\n", 1 << 4);
	printf("%x\n", 1 << 10);
	printf("%d\n", 1 << 10);
	printf("%\n", 2);
	printf("%lu\n", 2);
	printf("%d\n", 2);
	unsigned long long int num = 285212672; //FYI: fits in 29 bits
	int normalInt = 5;
	printf("My number is %d bytes wide and its value is %llu. A normal number is %d.\n", sizeof(num), num, normalInt);
	
	int netData = htonl(0x1234);
	int hostData = ntohl(netData);	 
	unsigned short a = 0x01;
	printf("htons=%d htonl=%d  ntohl=%d\n", htons(a) , netData, hostData);
	
	char * p = "asdbasfaf";
	printf("%s" , p);
	
}