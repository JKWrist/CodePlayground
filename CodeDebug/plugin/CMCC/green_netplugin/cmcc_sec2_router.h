#ifndef _CMCC_SEC2_ROUTER_H_
#define _CMCC_SEC2_ROUTER_H_

#ifdef __cplusplus
extern "C" {
#endif
/*==============================================================================
cmcc_sec2_router.h

类功能描述：
cmcc_sec2_router接口模块以外部接口调用的形式提供给调用者，
以便调用者能通过API调用路由器的基础能力

外部接口功能：
	(1)、获取设备软硬件信息
	(2)、获取设备WAN口的IPv4IPv6地址信息
	(3)、获取路由器LAN口Mac地址
	(4)、获取路由器WAN口Mac地址
	(5)、获取路由器启动后持续的时间
	(6)、重启路由器
	(7)、获取路由器CPU使用率
	(8)、获取路由器RAM使用率
	(9)、获取WAN口实时上下行速率
	(10)、获取下挂设备信息（包括LAN和WiFi接入的设备）
	(11)、清空硬加速链接跟踪表
	(12)、设置硬加速链接跟踪前，软件协议栈处理报文数量
	(13)、设置工作模式
	(14)、设置指定设备MAC的速率
	(15)、查询当前配置限速设备的信息
	
==============================================================================*/

#define EXTEND_WIFI6

/*厂商信息字段最大长度*/
#ifndef SEC_VENDOR_MAX_LENGTH
#define SEC_VENDOR_MAX_LENGTH           64
#endif

/*路由器型号字段最大长度*/
#ifndef SEC_PRODUCTCLASS_MAX_LENGTH
#define SEC_PRODUCTCLASS_MAX_LENGTH     64
#endif

/*路由器硬件版本信息字段最大长度*/
#ifndef SEC_HDVER_MAX_LENGTH
#define SEC_HDVER_MAX_LENGTH            32
#endif

/*路由器固件版本信息字段最大长度*/
#ifndef SEC_FMVER_MAX_LENGTH
#define SEC_FMVER_MAX_LENGTH            32
#endif

/*路由器SN序列号字段最大长度*/
#ifndef SEC_SN_MAX_LENGTH
#define SEC_SN_MAX_LENGTH               128
#endif

/*路由器CMEI序列号字段最大长度*/
#ifndef SEC_CMEI_MAX_LENGTH
#define SEC_CMEI_MAX_LENGTH             128
#endif


/*下挂设备名称最大长度*/
#ifndef SEC_MAX_DEVNAME_LENGTH
#define SEC_MAX_DEVNAME_LENGTH          256
#endif

/*ipv4地址最大长度*/
#ifndef SEC_MAX_IPV4_LENGTH
#define SEC_MAX_IPV4_LENGTH             20
#endif

/*ipv6地址最大长度*/
#ifndef SEC_MAX_IPV6_LENGTH
#define SEC_MAX_IPV6_LENGTH             64
#endif

/*mac地址最大长度*/
#ifndef SEC_MAX_MAC_LENGTH
#define SEC_MAX_MAC_LENGTH              20
#endif

/*最大下挂设备数量(WiFi6)*/
#ifndef SEC_MAX_DEV_CNT
#define SEC_MAX_DEV_CNT                 256
#endif

/*最大预留空间*/
#ifndef SEC_MAX_LENGTH
#define SEC_MAX_LENGTH                  32
#endif


/**
 * 路由器信息
 */
#pragma pack(4)
typedef struct {

    int  workmode;											//工作模式，0：桥接模式；1：路由模式；2：中继模式 
    int  mesh_status;										//mesh状态，0：主设备；  1：从设备；2：不支持mesh
    char vendor[SEC_VENDOR_MAX_LENGTH];						//厂商信息
    char product_class[SEC_PRODUCTCLASS_MAX_LENGTH];		//路由器型号
    char hardware_ver[SEC_HDVER_MAX_LENGTH];				//路由器硬件版本
    char firmware_ver[SEC_FMVER_MAX_LENGTH];				//路由器固件软件版本
    char serial_num[SEC_SN_MAX_LENGTH];						//路由器序列号
    char cmei[SEC_CMEI_MAX_LENGTH];							//路由器CMEI
#ifdef EXTEND_WIFI6
	int  mesh_switch;										//mesh开关状态：0：mesh关闭；	1：mesh开启；	-1：不支持mesh
	char province[SEC_MAX_LENGTH];							//省份标识
#endif

} sec_router_info;
#pragma pack()


/**
 * 下挂设备信息
 */
#pragma pack(4)
typedef struct {

    int  status;										//下挂设备状态，取值释义:0-ONLINE，只关注ONLINE设备；
    int  online_time;									//下挂设备在线时长，单位为秒；
	int  up_speed;										//下挂设备实时上行速率 单位kbps
	int  down_speed;									//下挂设备实时下行速率 单位kbps
	int  access_type;									//下挂设备对应接入类型，0: 有线，1: 2.4G无线，2: 5G无线
	int  signal_strength;								//下挂设备强度dBm(有线连接时为0)
    char device_name[SEC_MAX_DEVNAME_LENGTH];           //下挂设备名称
    char ipv4[SEC_MAX_IPV4_LENGTH];                     //下挂设备ipv4地址,返回格式形如“192.168.1.1“
	char ipv6[SEC_MAX_IPV6_LENGTH];						//下挂设备ipv6地址,返回格式形如”2409:8728:ef1:c:c05e:e3e8:75d3:9584“
    char mac[SEC_MAX_MAC_LENGTH];                       //下挂设备mac地址，返回格式为“XX:XX:XX:XX:XX:XX”
    char access_time[SEC_MAX_LENGTH];					//下挂设备接入时间
#ifdef EXTEND_WIFI6		
	char device_vendor[SEC_VENDOR_MAX_LENGTH];			//下挂设备归属的厂家
#endif		
    char rsv[SEC_MAX_LENGTH];							//预留字段
    
} sec_device_info;
#pragma pack()


/**
 * 限速设备信息
 */
#pragma pack(4)
typedef struct {

    char mac[SEC_MAX_MAC_LENGTH];											//下挂设备mac地址，返回格式为“XX:XX:XX:XX:XX:XX”
    unsigned int up_speed;														//下挂设备上行限速值(kbps)，未限速时为零
    unsigned int down_speed;													//下挂设备下行限速值(kbps)，未限速时为零
    
} sec_device_speed_limit_info;
#pragma pack()

/*=======================================================================
 *                           模块外部调用接口
======================================================================*/

/**
 * 获取设备软硬件信息
 * @param  [OUT] router_info,路由器软硬件信息结构体
 * @return 查询成功返回0，其它为-1；
 */
int sec_get_router_info(sec_router_info *router_info);

/**
 * 获取设备WAN口的IPv4IPv6地址信息
 * @param  [OUT] ipv4,ipv6,路由器WAN口IPv4和IPv6地址，IPv4以“X.X.X.X”格式输出，IPv6以“X:X:X:X”或“X:X::X”格式输出
 * @return 查询成功返回0，其它为-1；
 */
int sec_get_router_wan_ip(char *ipv4, char *ipv6);

/**
 * 获取路由器LAN口Mac，可作为设备标识，mac最大长度值为SEC_MAX_MAC_LENGTH
 * @param [OUT] lan_mac,路由器Mac地址,格式“XX:XX:XX:XX:XX:XX”
 * @return 成功返回0，其它为-1；
 */

int sec_get_router_lan_mac(char *lan_mac);

/**
 * 获取路由器WAN口Mac，可作为设备标识，mac最大长度值为SEC_MAX_MAC_LENGTH
 * @param [OUT] wan_mac,路由器Mac地址,格式“XX:XX:XX:XX:XX:XX”
 * @return 成功返回0，其它为-1；
 */

int sec_get_router_wan_mac(char *wan_mac);

/**
 * 获取路由器启动后持续的时间
 *
 * @return 运行时间，单位秒
 */
int sec_get_router_uptime(void);

/**
 * 重启路由器
 *
 * @return 0：成功； -1：失败
 */
int sec_reset(void);


/**
 * 获取路由器CPU使用率
 * @return 占用率，取值区间[0,100]，若取值发生异常，则返回-1
 */
int sec_get_cpu_occupancy_rate(void);

/**
 * 获取路由器RAM使用率
 *
 * @return 占用率，取值区间[0,100]，若取值发生异常，则返回-1
 */
int sec_get_ram_occupancy_rate(void);

/**
 *  WAN口实时速率查询，异步非阻塞接口
 *  @param [OUT] up_speed   上行速率,单位kbps
 *  @param [OUT] down_speed 下行速率,单位kbps
 *  @return 查询成功返回0，其它为-1；
 */
int sec_set_get_wan_speed(int *up_speed, int *down_speed);


/**
 * 获取下挂设备信息（包括LAN和WiFi接入的设备）
 * @param [OUT] dev_num  下挂设备信息数量,最大下挂设备数量为SEC_MAX_DEV_CNT
 * @param [OUT] dev_info 下挂设备信息集合
 * @return 查询成功返回0，其它为-1；
 */
int sec_get_dev_info(int *dev_num, sec_device_info *dev_info);


/**
 * 清空硬加速链接跟踪表
 * @return 清空操作成功返回0，其它为-1；
 */
int sec_set_hwnat_clean(void);


/**
 * 设置硬加速链接跟踪前，软件协议栈处理报文数量
 * @param [IN] count  设置每个数据流软件协议栈处理报文个数，-1：关闭硬加速功能；0：报文均走硬加速；其它：报文在协议栈处理的数量
 * @return 设置成功返回0，其它为-1；
 */
int sec_set_kernel_count(int count);


/**
 * 设置工作模式
 * @param [IN] mode 工作模式，0：桥接模式；1：路由模式；2：中继模式
 * @return 查询成功返回0，其它为-1；
 */
int sec_set_work_mode(int mode);

/**
 * 设置指定设备MAC的速率
 * @param [IN] dev_mac 指定(下挂)设备的MAC地址,最多支持设备数量为SEC_MAX_DEV_CNT
 * @param [IN] up_speed 上行速率，0：取消上线限速；其它：限速值，单位kbps
 * @param [IN] down_speed 下行速率，0：取消下行限速；其它：限速值，单位kbps
 * @return 查询成功返回0，其它为-1；
 */
int sec_set_dev_speed(char *dev_mac, int up_speed, int down_speed);

/**
 * 查询M当前配置限速设备的信息
 * @param [OUT] dev_num 下挂设备信息数量,最大下挂设备数量为SEC_MAX_DEV_CNT
 * @param [OUT] dev_speed_info 下挂设备和限速速率信息，0：取消上线限速；其它：限速值，单位kbps
 * @return 查询成功返回0，其它为-1；
 */
int sec_get_dev_speed(int *dev_num, sec_device_speed_limit_info *dev_speed_info);

/*=======================================================================*/

#ifdef __cplusplus
}
#endif

#endif
