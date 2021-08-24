#include <stdio.h>
#include <arpa/inet.h>
int main(int argc, char *argv[]) 
{
	unsigned short host_port = 0x1234;
	unsigned short net_port;
	unsigned long host_addr = 0x12345678;
	unsigned long net_addr;
	
	net_addr = htonl(host_addr);
	net_port = htons(host_port);
	
	printf("Host order port: %#x \n", host_port);
	printf("Net order port: %#x \n", net_port);
	printf("Host order addr: %#x \n", host_addr);
	printf("Net order addr: %#x \n", net_addr);
}