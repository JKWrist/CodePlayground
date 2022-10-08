#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
0: mean WAN
1: mean LAN
2: mean WLAN
*/
int rtk_intf_get_intf_by_ip(char* ipaddr)
{
	char cmd[256] ={0};
	char intf[15] ={0};
	char mac[32] ={0};
	char portno[15] ={0};
	char ifname[15] ={0};
	
	sprintf(cmd,"ip neigh | grep %s | awk '{print $3}'", ipaddr);
	// strcpy(cmd, "arp -a|grep 52");
	FILE *pp = popen(cmd, "r");

	if(pp){
		char *p1 = fgets(intf, 15, pp);
		printf("111 p1:%s\n", p1);
		pclose(pp);
		// intf[strlen(intf)-1]='\0';

		printf("111 intf :%s\n", intf);
		if(strstr(intf, "nas") || strstr(intf, "ppp")){
			return 1;
		}
	}

	//get mac addr
	sprintf(cmd,"ip neigh | grep %s | awk '{print $5}'", ipaddr);
	pp = popen(cmd, "r");

	if(pp){
		fgets(mac, 32, pp);
		pclose(pp);
		// mac[strlen(mac)-1]='\0';

		printf("2222 %s\n", cmd);
	}
	
	//get the specific mac bridge port no.
	sprintf(cmd,"brctl showmacs %s | grep %s | awk '{print $1}'", intf, mac);
	printf("3333 %s\n", cmd);
	pp = popen(cmd, "r");

	

	if(pp){
		fgets(portno, 15, pp);
		pclose(pp);
		printf("4444 %s\n", portno);
	// 	//get real interface name by bridge port no.
	// 	if (rtk_bridge_get_ifname_by_portno(intf, atoi(portno), ifname) == 0){
	// 		//printf("intf=%s,portno=%s,ifname=%s\n", intf,portno,ifname);
	// 		if(strstr(ifname, "wlan")){
	// 			return 2; //WLAN
	// 		}
	// 		else{
	// 			return 0; //LAN
	// 		}
	// 	}else
	// 		return -1;
	}

	return -1;
}

int main()
{
	rtk_intf_get_intf_by_ip("192.168.146.2");
	return 0;
}