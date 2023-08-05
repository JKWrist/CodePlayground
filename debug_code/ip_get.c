/**
 * get IPv4 address and subnet mask of a network interface
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <arpa/inet.h>
	
int main(int argc, char *argv[])
{
	int rc = 0;
	struct sockaddr_in *addr = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <ifname>", argv[0]);
		return -1;
	}

	char *ifname = argv[1];

	struct ifreq ifr;
	memset(&ifr, 0, sizeof(struct ifreq));

	/* 0. create a socket */
	int fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
	if (fd == -1)
		return -1;

	/* 1. set type of address to retrieve : IPv4 */
	ifr.ifr_addr.sa_family = AF_INET;

	/* 2. copy interface name to ifreq structure */
	strncpy(ifr.ifr_name, ifname, IFNAMSIZ - 1);

	/* 3. get the IP address */
	if ((rc = ioctl(fd, SIOCGIFADDR, &ifr)) != 0)
	{
		printf("get ip error\n");
		goto done;
	}

	char ipv4[16] = { 0 };
	addr = (struct sockaddr_in *)&ifr.ifr_addr;
	strncpy(ipv4, inet_ntoa(addr->sin_addr), sizeof(ipv4));

	/* 4. get the mask */
	if ((rc = ioctl(fd, SIOCGIFNETMASK, &ifr)) != 0)
	{
		printf("get mask error\n");
		goto done;
	}

	char mask[16] = { 0 };
	addr = (struct sockaddr_in *)&ifr.ifr_addr;
	strncpy(mask, inet_ntoa(addr->sin_addr), sizeof(mask));

	/* 5. display */
	printf("IFNAME:IPv4:MASK\n");
	printf("%s:%s:%s\n", ifname, ipv4, mask);

	/* 6. close the socket */
done:
	close(fd);
	return rc;
}