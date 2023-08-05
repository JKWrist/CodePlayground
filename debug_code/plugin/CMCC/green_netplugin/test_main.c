#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmcc_sec2_router.h"

static void _string_upper(char *s)
{	
	while (*s != '\0') 
	{		
		if (islower(*s))			
			*s = toupper(*s);		
		s++;	
	}
}


int main(int argc, char **argv)
{
	int ret = -1;
#if 1
	int mode = 1;

	if (argc > 1 && !strncmp(argv[1], "bridge", 4))
	{
		ret = sec_set_work_mode(mode);
		if (ret == 0)
			printf("sec_set_work_mode: %d\n", mode);
		else
			printf("sec_set_work_mode error\n");

		return 0;
	}

	sec_router_info router_info={0};
	ret = sec_get_router_info(&router_info);
	if (ret == 0)
	{
		printf("workmode: %d\n", router_info.workmode);
		printf("mesh_status: %d\n", router_info.mesh_status);
		printf("vendor: %s\n", router_info.vendor);
		printf("product_class: %s\n", router_info.product_class);
		printf("hardware_ver: %s\n", router_info.hardware_ver);
		printf("firmware_ver: %s\n", router_info.firmware_ver);
		printf("serial_num: %s\n", router_info.serial_num);
		printf("cmei: %s\n", router_info.cmei);
		printf("mesh_switch: %d\n",router_info.mesh_switch);
		printf("province: %s\n",router_info.province);

	}
	else
		printf("sec_get_router_info error\n");

	sec_set_hwnat_clean();	

	sec_set_kernel_count(30);

	char ipv4[SEC_MAX_IPV4_LENGTH]={0},ipv6[SEC_MAX_IPV6_LENGTH]={0};
	ret = sec_get_router_wan_ip(ipv4,ipv6);
	if(ret ==0)
		printf("ipv4=%s,ipv6=%s\n",ipv4,ipv6);
	else
		printf("sec_get_router_wan_ip error\n");

	char wlan_mac[SEC_MAX_MAC_LENGTH] = {0};
	ret = sec_get_router_lan_mac(wlan_mac);
	_string_upper(wlan_mac);
	if (ret == 0)
		printf("wlan_mac: %s\n", wlan_mac);
	else
		printf("sec_get_router_lan_mac error\n");

	char wan_mac[SEC_MAX_MAC_LENGTH] = {0};
	ret = sec_get_router_wan_mac(wan_mac);
	_string_upper(wan_mac);
	if (ret == 0)
		printf("wan_mac: %s\n", wan_mac);
	else
		printf("sec_get_router_wan_mac error\n");

	printf("sec_get_router_uptime: %d\n", sec_get_router_uptime());

	//	sec_reset();

	printf("sec_get_cpu_occupancy_rate: %d\n", sec_get_cpu_occupancy_rate());
	printf("sec_get_ram_occupancy_rate: %d\n", sec_get_ram_occupancy_rate());

	int up_speed = 0, down_speed = 0;
	ret = sec_set_get_wan_speed(&up_speed, &down_speed);
	if (ret == 0)
		printf("up_speed: %d, down_speed: %d\n", up_speed, down_speed);
	else
		printf("sec_set_get_wan_speed error\n");


	int dev_num = 0, i = 0;
	sec_device_info dev_info[SEC_MAX_DEV_CNT] = {0};
	ret = sec_get_dev_info(&dev_num, dev_info);
	if (ret == 0)
	{
		for(i = 0; i < dev_num; i++)
		{
			printf("status: %d\n", dev_info[i].status);
			printf("online_time: %d\n", dev_info[i].online_time);
			printf("up_speed: %d\n", dev_info[i].up_speed);
			printf("down_speed: %d\n", dev_info[i].down_speed);
			printf("access_type: %d\n", dev_info[i].access_type);
			printf("signal_strength: %d\n", dev_info[i].signal_strength);
			printf("device_name: %s\n", dev_info[i].device_name);
			printf("ipv4: %s\n", dev_info[i].ipv4);
			printf("ipv6: %s\n", dev_info[i].ipv6);
			printf("mac: %s\n", dev_info[i].mac);
			printf("access_time: %s\n", dev_info[i].access_time);
			printf("device_vendor: %s\n",dev_info[i].device_vendor);
			printf("rsv: %s\n", dev_info[i].rsv);
			printf(" \n");
		}
	}
	else
		printf("sec_get_router_info error\n");
	
	printf("Get Speed limit info:------\n");
	sec_device_speed_limit_info dev_speed_info[SEC_MAX_DEV_CNT] = {0};
	int device_num = 0;
		
	if(!sec_get_dev_speed(&device_num,&dev_speed_info)){
		printf("numb=%d\n",device_num);
		for(i=0;i<device_num;i++){
			printf("mac:%s,upSpeed:%d,downSpeed:%d\n",dev_speed_info[i].mac,dev_speed_info[i].up_speed,dev_speed_info[i].down_speed);
		}
	}
	else
		printf("Get speed limit fail\n");
	
	char *test_dev_mac;
	int test_upSpeed=0,test_downSpeed=0;
	if (argc > 1 && !strncmp(argv[1], "set_qos", strlen(argv[1]))){
		printf("Set Speed limit:------\n");
		if(argc==5){
			test_dev_mac = argv[2];
			test_upSpeed = atoi(argv[3]);
			test_downSpeed = atoi(argv[4]);
			if(!sec_set_dev_speed(test_dev_mac,test_upSpeed,test_downSpeed))
				printf("set success!\n");
			else
				printf("set fail!\n");
		}
	}
#endif	
	return 0;
}
