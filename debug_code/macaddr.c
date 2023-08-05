/*
flash get ELAN_MAC_ADDR
ELAN_MAC_ADDR=34fca1ac8811
macaddr
34:fc:a1:ac:88:12
*/

#include <stdio.h>

int main()
{
	char labelMac[32] = {0};
	unsigned char eLanMac[6] = "0x34fca1ac8811";
	sprintf(labelMac, "%02X%02X%02X%02X%02X%02X",
			eLanMac[0], eLanMac[1], eLanMac[2], eLanMac[3], eLanMac[4], eLanMac[5]);
	printf("%02X%02X%02X%02X%02X%02X\n",
			eLanMac[0], eLanMac[1], eLanMac[2], eLanMac[3], eLanMac[4], eLanMac[5] + 1);
	printf("%s\n", labelMac);
	return 0;
}