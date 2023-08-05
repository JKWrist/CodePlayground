
#include <sys/time.h>
#include "cmcc_sec2_router.h"

#include "rtk_isp_common_utility.h"
#include "rtk_isp_wlan_adapter.h"
#include "rtk_isp_lan_adapter.h"
#include "rtk_isp_wan_adapter.h"
#include "rtk_isp_ethernet_adapter.h"
#include "rtk_isp_qos_adapter.h"
#include "rtk_isp_multicast_adapter.h"
#include "rtk_isp_firewall_adapter.h"
#include "rtk_isp_other_adapter.h"
#include "rtk_isp_diagnostics_adapter.h"
#include "rtk_isp_serverinfo_adapter.h"
#include "rtk_isp_system_adapter.h"
#include "fc_api.h"

#ifdef DEBUG_CMCC_GREE
#define DEBUG_ERROR(fmt, args...) printf(fmt, ##args)
#else
#define DEBUG_ERROR(fmt, args...)
#endif

/**
 *  * 获取设备软硬件信息
 *   * @param  [OUT] router_info,路由器软硬件信息结构体
 *    * @return 查询成功返回0，其它为-1；
 *     */
int sec_get_router_info(sec_router_info *router_info)
{
    char opmode=0;
    char tmpBuf[128]={0};
    Easymesh_Config_T mesh_conf;
    unsigned char serialNumber[128]={0};
    unsigned char prov[8]={0};

    if(router_info==NULL)
        return -1;

    if(rtk_system_get_opmode(&opmode)==RTK_SUCCESS)
    {
        if(opmode==BRIDGE_MODE)
            router_info->workmode=0;
        else if(opmode==GATEWAY_MODE)
            router_info->workmode=1;
        else if(opmode==REPEATER_MODE)
            router_info->workmode=2;
    }
    else
        DEBUG_ERROR("[%s] (%d)get opmode fail\n",__FUNCTION__,__LINE__);

    memset(&mesh_conf, 0, sizeof(Easymesh_Config_T));
#ifdef WLAN_RTK_MULTI_AP
    if(rtk_system_get_meshConfig(&mesh_conf)==RTK_SUCCESS)
    {
        if(mesh_conf.mode == MAP_CONTROLLER)
            router_info->mesh_status=0;
        else if(mesh_conf.mode == MAP_AGENT)
            router_info->mesh_status=1;
        else if(mesh_conf.mode == MAP_DISABLED)
            router_info->mesh_status=2;
    }
#else
    DEBUG_ERROR("[%s] (%d)not support easy mesh\n",__FUNCTION__,__LINE__);
#endif
    strncpy(router_info->vendor,DEF_MANUFACTURER_STR,sizeof(router_info->vendor));
    strncpy(router_info->product_class,"e-OS AP",sizeof(router_info->product_class));

    if(rtk_system_get_hw_version(tmpBuf, sizeof(tmpBuf))==RTK_SUCCESS)
        strncpy(router_info->hardware_ver,tmpBuf,sizeof(router_info->hardware_ver));


    if(rtk_system_get_sw_version(tmpBuf, sizeof(tmpBuf))==RTK_SUCCESS)
        strncpy(router_info->firmware_ver,tmpBuf,sizeof(router_info->firmware_ver));

    mib_get_s(MIB_HW_SERIAL_NUMBER, serialNumber, sizeof(serialNumber));
    strncpy(router_info->serial_num,serialNumber,sizeof(router_info->serial_num));

    mib_get_s(MIB_HW_CMEI_NUMBER, router_info->cmei, sizeof(router_info->cmei));
#ifdef EXTEND_WIFI6
#ifdef WLAN_RTK_MULTI_AP
    if(mesh_conf.mode == MAP_CONTROLLER || mesh_conf.mode == MAP_AGENT)
        router_info->mesh_switch = 1;
    else if(mesh_conf.mode == MAP_DISABLED)
        router_info->mesh_switch = 0;
    else
#endif
        router_info->mesh_switch = -1;
#ifdef CONFIG_E8B
    mib_get_s(MIB_HW_PROVINCE_NAME, prov, sizeof(prov));
    snprintf(router_info->province, sizeof(router_info->province), "%s", prov);
#endif
#endif/*EXTEND_WIFI6*/
    return 0;	
}

/**
 *  * 获取设备WAN口的IPv4IPv6地址信息
 *   * @param  [OUT] ipv4,ipv6,路由器WAN口IPv4和IPv6地址，IPv4以“X.X.X.X”格式输出，IPv6以“X:X:X:X”或“X:X::X”格式输出
 *    * @return 查询成功返回0，其它为-1；
 *     */
int sec_get_router_wan_ip(char *ipv4, char *ipv6)
{
    if((ipv4==NULL)||(ipv6==NULL))
        return -1;

    IPV4_ADDR_INFO ipv4_addr_info;
#ifdef CONFIG_IPV6
    IPV6_ADDR_INFO ipv6_addr_info;
#endif
    int wan_idx=0;
    char opmode;
    char tmpBuf[128]={0};

    rtk_system_get_opmode(&opmode);

    memset(&ipv4_addr_info, 0, sizeof(ipv4_addr_info));
    if(opmode==GATEWAY_MODE)
        rtk_wan_get_ipv4_address_info(wan_idx, &ipv4_addr_info);
    else
        rtk_lan_get_ipv4_address_info(&ipv4_addr_info);
    snprintf(ipv4, SEC_MAX_IPV4_LENGTH, "%s", inet_ntoa(*((struct in_addr *)&ipv4_addr_info.ip)));

#ifdef CONFIG_IPV6
    memset(&ipv6_addr_info, 0, sizeof(ipv6_addr_info));
    rtk_wan_get_ipv6_address_info(wan_idx, &ipv6_addr_info);
    snprintf(ipv6, SEC_MAX_IPV6_LENGTH, "%s", ipv6_addr_info.ipv6_global_addr);	
#endif
    return 0;
}

/**
 *  * 获取路由器LAN口Mac，可作为设备标识，mac最大长度值为SEC_MAX_MAC_LENGTH
 *   * @param [OUT] lan_mac,路由器Mac地址,格式“XX:XX:XX:XX:XX:XX”
 *    * @return 成功返回0，其它为-1；
 *     */
int sec_get_router_lan_mac(char *lan_mac)
{
    unsigned char macStr[SEC_MAX_MAC_LENGTH] = {0};

    if((lan_mac==NULL)||(rtk_system_get_router_mac(macStr)==RTK_FAILED))
        return -1;

    snprintf(lan_mac, SEC_MAX_MAC_LENGTH, "%02x:%02x:%02x:%02x:%02x:%02x", macStr[0],macStr[1],macStr[2],macStr[3],macStr[4],macStr[5]);
    return 0;

}
/**
 *  * 获取路由器WAN口Mac，可作为设备标识，mac最大长度值为SEC_MAX_MAC_LENGTH
 *   * @param [OUT] wan_mac,路由器Mac地址,格式“XX:XX:XX:XX:XX:XX”
 *    * @return 成功返回0，其它为-1；
 *     */
int sec_get_router_wan_mac(char *wan_mac)
{
    struct sockaddr hwaddr;
    unsigned char macStr[SEC_MAX_MAC_LENGTH] = {0};

    if((wan_mac==NULL)||(getInAddr(WAN_IF, HW_ADDR, (void *)&hwaddr)==RTK_FAILED))
        return -1;

    memcpy(macStr, (unsigned char *)hwaddr.sa_data, 6);
    snprintf(wan_mac, SEC_MAX_MAC_LENGTH, "%02x:%02x:%02x:%02x:%02x:%02x", macStr[0],macStr[1],macStr[2],macStr[3],macStr[4],macStr[5]);
    return 0;
}

/**
 *  * 获取路由器启动后持续的时间
 *   *
 *    * @return 运行时间，单位秒
 *     */
int sec_get_router_uptime(void)
{
    double uptime=0;
    rtk_system_get_uptime(&uptime);
    return uptime;
}

/**
 *  * 重启路由器
 *   *
 *    * @return 0：成功； -1：失败
 *     */
int sec_reset(void)
{
    if(cmd_reboot()==1)
        return 0;
    else
        return -1;
}

/**
 *  * 获取路由器CPU使用率
 *   * @return 占用率，取值区间[0,100]，若取值发生异常，则返回-1
 *    */
int sec_get_cpu_occupancy_rate(void)
{
    int cpu_idx=-1;
    float cpu_usage_f=0;
    unsigned int cpuusage=0;	
    if(rtk_mgmt_get_cpu_usage(cpu_idx, &cpu_usage_f)==RTK_SUCCESS)
    {
        cpuusage = (unsigned int)(cpu_usage_f+0.5);
        if(cpuusage==0) cpuusage=1;
        return cpuusage;
    }else
        return -1;

}

/**
 *  * 获取路由器RAM使用率
 *   *
 *    * @return 占用率，取值区间[0,100]，若取值发生异常，则返回-1
 *     */
int sec_get_ram_occupancy_rate(void)
{
    int memusage=0;
    MEMINFO_USER_T mem_info;
    if(rtk_get_memory_user(&mem_info)==RTK_SUCCESS)
    {
        memusage=100-(mem_info.mem_free*100/mem_info.mem_userTotal);
        return memusage;
    }else
        return -1;
}

/**
 *  *  WAN口实时速率查询，异步非阻塞接口
 *   *  @param [OUT] up_speed   上行速率,单位kbps
 *    *  @param [OUT] down_speed 下行速率,单位kbps
 *     *  @return 查询成功返回0，其它为-1；
 *      */
int sec_set_get_wan_speed(int *up_speed, int *down_speed) 
{
    int wan_port= (-1);
    unsigned int tmp_up_speed=0, tmp_down_speed=0;

    if((up_speed==NULL)||(down_speed==NULL))
        return -1;

    wan_port = rtk_port_get_wan_phyID();

    if(wan_port >= 0)  //ethernet up
    {
        rtk_ethernet_get_port_speed(wan_port, &tmp_up_speed, &tmp_down_speed);
        tmp_up_speed = (tmp_up_speed*8/1000);
        tmp_down_speed = (tmp_down_speed*8/1000);
        *up_speed = tmp_up_speed;
        *down_speed = tmp_down_speed;
        return 0;
    }

    return (-1);

}

/**
 *  * 获取下挂设备信息（包括LAN和WiFi接入的设备）
 *   * @param [OUT] dev_num  下挂设备信息数量,最大下挂设备数量为SEC_MAX_DEV_CNT
 *    * @param [OUT] dev_info 下挂设备信息集合
 *     * @return 查询成功返回0，其它为-1；
 *      */
int sec_get_dev_info(int *dev_num, sec_device_info *dev_info)
{
    int client_num=0,i=0;
    cmccGreeLanDev_T lanClient[SEC_MAX_DEV_CNT] = {0};
    unsigned int count;

    if((dev_num==NULL)||(dev_info==NULL))
        return -1;

	if (rtk_cmcc_get_lanDevInfo(lanClient, SEC_MAX_DEV_CNT, &count) == RTK_FAILED)
	{
		DEBUG_ERROR("(%s)%d get lan net info failed!\n", __FUNCTION__, __LINE__);
			return -1;
	}

    for(i=0; i<SEC_MAX_DEV_CNT; i++)
    {
        if(lanClient[i].is_alive)
        {
            client_num++;
            dev_info[client_num-1].status = 0;
            dev_info[client_num-1].online_time = lanClient[i].link_time;
            dev_info[client_num-1].up_speed = (lanClient[i].up_speed*8/1024);
            dev_info[client_num-1].down_speed = (lanClient[i].down_speed*8/1024);
            if(lanClient[i].conn_type==LAN_DEV_CONN_WIRED)
                dev_info[client_num-1].access_type = 0;
            else if(lanClient[i].conn_type==LAN_DEV_CONN_WLAN_2G)
                dev_info[client_num-1].access_type = 1;
            else if(lanClient[i].conn_type==LAN_DEV_CONN_WLAN_5G)
                dev_info[client_num-1].access_type = 2;
            else
                DEBUG_ERROR("error conn_type=%d\n",lanClient[i].conn_type);

            if(lanClient[i].conn_type==LAN_DEV_CONN_WIRED)
                dev_info[client_num-1].signal_strength = 0;
            else
                dev_info[client_num-1].signal_strength = (int)lanClient[i].rssi - 100;

			snprintf(dev_info[client_num-1].device_name, sizeof(dev_info[client_num-1].device_name), "%s", lanClient[i].dev_name);
			snprintf(dev_info[client_num-1].ipv4, sizeof(dev_info[client_num-1].ipv4), "%s", inet_ntoa(*((struct in_addr *)&lanClient[i].ip)));
			snprintf(dev_info[i].ipv6, sizeof(dev_info[i].ipv6), "%s", lanClient[i].ipv6Addr);
			snprintf(dev_info[client_num-1].mac, sizeof(dev_info[client_num-1].mac), "%02X:%02X:%02X:%02X:%02X:%02X",
				lanClient[i].mac[0], lanClient[i].mac[1],lanClient[i].mac[2], lanClient[i].mac[3], lanClient[i].mac[4], lanClient[i].mac[5]);

            snprintf(dev_info[client_num-1].access_time, sizeof(dev_info[client_num-1].access_time), "%s", lanClient[i].access_time);
            snprintf(dev_info[client_num-1].device_vendor, sizeof(dev_info[client_num-1].device_vendor), "%s", lanClient[i].brand);
        }
    }

    *dev_num = client_num;
    return 0;
}

/**
 *  * 清空硬加速链接跟踪表
 *    */
int sec_set_hwnat_clean(void)
{
    rtk_fc_flow_flush();
    return 0;
}

/**
 *  * 设置硬加速链接跟踪前，软件协议栈处理报文数量
 *   * @param [OUT] count  设置每个数据流软件协议栈处理报文个数，-1：关闭硬加速功能；0：报文均走硬加速；其它：报文在协议栈处理的数量
 *    * @return 设置成功返回0，其它为-1；
 *	   */
int sec_set_kernel_count(int count)
{
	char command[128] = {0};

	if (count < -1)
		return -1;

	if (count == -1) {
		system("/bin/echo 1 > /proc/fc/ctrl/trap_to_ps");
	}
	else if (count == 0) {
		system("/bin/echo count 0 > /proc/fc/ctrl/flow_delay");
		system("/bin/echo 0 > /proc/fc/ctrl/trap_to_ps");
	}
	else {
		system("/bin/echo mode kernel > /proc/fc/ctrl/flow_delay");
		snprintf(command, sizeof(command), "/bin/echo count %d > /proc/fc/ctrl/flow_delay", count);
		system(command);

		system("/bin/echo 0 > /proc/fc/ctrl/trap_to_ps");
	}

	return 0;
}

/**
 *  * 设置工作模式
 *   * @param [IN] mode 工作模式，0：桥接模式；1：路由模式；2：中继模式
 *    * @return 查询成功返回0，其它为-1；
 *     */
int sec_set_work_mode(int mode)
{
    int ret=RTK_FAILED;
    if(mode==0)
        ret=rtk_system_set_opmode(1);
    else if(mode==1)
        ret=rtk_system_set_opmode(0);
    else if(mode==2)
        ret=rtk_system_set_opmode(3);

    return ret;
}

/**
 * 设置指定设备MAC的速率
 * @param [IN] dev_mac 指定(下挂)设备的MAC地址,最多支持设备数量为SEC_MAX_DEV_CNT
 * @param [IN] up_speed 上行速率，0：取消上线限速；其它：限速值，单位kbps
 * @param [IN] down_speed 下行速率，0：取消下行限速；其它：限速值，单位kbps
 * @return 查询成功返回0，其它为-1；
 */
int sec_set_dev_speed(char *dev_mac, int up_speed, int down_speed){
	QOS_REQ_T req;
	unsigned int tmp_mac[6] = {0};

	if(!dev_mac || !isValidMacString(dev_mac)){
		DEBUG_ERROR("%s:%d Invalid mac address %s!\n",__FUNCTION__,__LINE__,dev_mac);
		return -1;
	}

	if((up_speed<QOS_SPEED_LIMIT_UNIT&&up_speed!=0) || up_speed>MAX_LINK_RATE || (down_speed<QOS_SPEED_LIMIT_UNIT&&down_speed!=0) || down_speed>MAX_LINK_RATE){
		DEBUG_ERROR("%s:%d Invalid speed limit, should be %d~%d or 0!\n",__FUNCTION__,__LINE__,QOS_SPEED_LIMIT_UNIT,MAX_LINK_RATE);
		return -1;
	}

	memset(&req, 0, sizeof(QOS_REQ_T));
	sscanf(dev_mac, "%2x:%2x:%2x:%2x:%2x:%2x",&tmp_mac[0],&tmp_mac[1],&tmp_mac[2],&tmp_mac[3],&tmp_mac[4],&tmp_mac[5]);
	snprintf(req.clientMAC,sizeof(req.clientMAC),"%02x%02x%02x%02x%02x%02x",tmp_mac[0],tmp_mac[1],tmp_mac[2],tmp_mac[3],tmp_mac[4],tmp_mac[5]);
	snprintf(req.maxDownlinkRate,sizeof(req.maxDownlinkRate),"%d",down_speed);
	snprintf(req.maxUplinkRate,sizeof(req.maxUplinkRate),"%d",up_speed);
	
	if(rtk_set_qos_info(&req)!=RTK_SUCCESS){
		DEBUG_ERROR("%s:%d Set rtk_set_qos_info failed!\n",__FUNCTION__,__LINE__);
		return -1;
	}

	return 0;
}

/**
 * 查询M当前配置限速设备的信息
 * @param [OUT] dev_num 下挂设备信息数量,最大下挂设备数量为SEC_MAX_DEV_CNT
 * @param [OUT] dev_speed_info 下挂设备和限速速率信息，0：取消上线限速；其它：限速值，单位kbps
 * @return 查询成功返回0，其它为-1；
 */
int sec_get_dev_speed(int *dev_num, sec_device_speed_limit_info *dev_speed_info){
	qos_tbl_info_T req;
	int i;
	unsigned char hex_mac[6] = {0};
	
	memset(&req, 0, sizeof(qos_tbl_info_T));
	if(rtk_get_qos_tbl_info(&req) != RTK_SUCCESS){
		DEBUG_ERROR("%s:%d Get rtk_get_qos_tbl_info failed!\n",__FUNCTION__,__LINE__);
		return -1;
	}

	if(req.qos_tbl_num>SEC_MAX_DEV_CNT){
		DEBUG_ERROR("%s:%d Device number %d exceeds SEC_MAX_DEV_CNT!\n",__FUNCTION__,__LINE__,req.qos_tbl_num);
		return -1;
	}

	*dev_num = req.qos_tbl_num;
	for(i=0;i<*dev_num;i++){
		if(!rtk_string_to_hex(req.qos_info[i].clientMAC,hex_mac,12)){
			DEBUG_ERROR("%s:%d rtk_string_to_hex failed!\n",__FUNCTION__,__LINE__);
			return -1;
		}
		snprintf(dev_speed_info[i].mac,sizeof(dev_speed_info[i].mac),"%02x:%02x:%02x:%02x:%02x:%02x",hex_mac[0],hex_mac[1],hex_mac[2],hex_mac[3],hex_mac[4],hex_mac[5]);
		dev_speed_info[i].down_speed = atoi(req.qos_info[i].maxDownlinkRate);
		dev_speed_info[i].up_speed = atoi(req.qos_info[i].maxUplinkRate);
	}
	return 0 ;
	
	
}

