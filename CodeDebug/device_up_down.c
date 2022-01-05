#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int PHYBAND_TYPE_T;
typedef int UPLINK_TYPE_T;

typedef struct STAInfo_s
{
    char mac[18];
    char clone_mac[18];
    char uptime[10];
    char port[10];
    PHYBAND_TYPE_T band;
    char ssid[MAX_SSID_LEN];
    char rssi[10];
    char ip_addr[16];
    char ip6_addr[40];
    char rxrate[10];
    char txrate[10];
    unsigned int cur_rxrate;
    unsigned int cur_txrate;
    UPLINK_TYPE_T uptype;
    char hostname[64];
} STAInfo;

// [{
//     "devId" : "2389293",
//     "services" : [ {
//         "data" : {
//             "mac" : "value1",  //设备mac地址
//             "name" : "value2", //设备名字
//             "time" : "value3", //设备接入时间
//             "type" : "value4", //设备接入类型, 1：下线，0：上线
//         }
//     } ]
// }]

/****************************************************************
 *  函数名称：
 *  创建日期：2021-12-29 16:51:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int IF5_event_STAstatus(void)
{
    DBG_PRINT("IF5_event_STAstatus!\n");

    List sta_list;
    STAInfo *sta = NULL;
    DEVInfo dev[MAX_STA_NUM];
    DEVInfo dev6[MAX_STA_NUM];
    char delete_delim_mac[13] = {0}, delete_delim_vmac[13] = {0};
    int i, ret = 0;

    list_init(&sta_list);
    ret = rtl_link_getWlanSTAInfo(&sta_list);
    if (ret == -1)
    {
        DBG_PRINT("ERROR (%s)%d error\n", __FUNCTION__, __LINE__);
        list_destroy(&sta_list, free);
        return -1;
    }
    ret = rtl_link_getLanDevInfo(&sta_list);
    if (ret == -1)
    {
        DBG_PRINT("ERROR (%s)%d error\n", __FUNCTION__, __LINE__);
        list_destroy(&sta_list, free);
        return -1;
    }
    memset(dev, 0, sizeof(dev));
    memset(dev6, 0, sizeof(dev6));
    rtl_link_staifRate(dev, sta_list.len, ifastatus);
    rtl_link_staifRate(dev6, sta_list.len, if6status);
    char *deviceId = getIF5DeviceId();

    cJSON *jsonSend = cJSON_CreateObject();
    cJSON_AddStringToObject(jsonSend, "deviceId", deviceId);
    cJSON_AddStringToObject(jsonSend, "eventType", "XData_STAInfo");
    cJSON_AddNumberToObject(jsonSend, "timestamp", get_time_ms());

    /*************** 数组 Devices *********************/
    cJSON *Devices = cJSON_CreateArray();

    for (i = 0; i < sta_list.len; i++)
    {
        sta = list_get_element(&sta_list, i);
        cJSON *Node = cJSON_CreateObject();

        rtl_link_macFormat(delete_delim_mac, sta->clone_mac);
        cJSON_AddStringToObject(Node, "MacAddress", delete_delim_mac);
        rtl_link_macFormat(delete_delim_vmac, sta->mac);
        cJSON_AddStringToObject(Node, "VMacAddress", delete_delim_vmac);
        cJSON_AddStringToObject(Node, "UpTime", sta->uptime);
        if (sta->uptype == WIRELESS_T)
        {
            if (sta->band == PHYBAND_2G)
            {
                cJSON_AddStringToObject(Node, "Radio", "2.4G");
            }
            else
            {
                cJSON_AddStringToObject(Node, "Radio", "5G");
            }

            cJSON_AddStringToObject(Node, "SSID", sta->ssid);
            cJSON_AddStringToObject(Node, "RSSI", sta->rssi);
            cJSON_AddStringToObject(Node, "RxRate", sta->rxrate);
            cJSON_AddStringToObject(Node, "TxRate", sta->txrate);
            if (!strcmp(sta->ip_addr, "0.0.0.0"))
            {
                cJSON_AddStringToObject(Node, "IPAddress", "");
            }
            else
            {
                cJSON_AddStringToObject(Node, "IPAddress", sta->ip_addr);
            }

            if (strcmp(sta->ip6_addr, "::"))
            {
                cJSON_AddStringToObject(Node, "STAIPv6IPAddress", sta->ip6_addr);
            }

            cJSON_AddStringToObject(Node, "HostName", sta->hostname);
        }
        else
        {
            cJSON_AddStringToObject(Node, "Radio", "");
            cJSON_AddStringToObject(Node, "SSID", "");
            cJSON_AddStringToObject(Node, "RSSI", "");
            cJSON_AddStringToObject(Node, "RxRate", sta->rxrate);
            cJSON_AddStringToObject(Node, "TxRate", sta->txrate);
            if (!strcmp(sta->ip_addr, "0.0.0.0"))
            {
                cJSON_AddStringToObject(Node, "IPAddress", "");
            }
            else
            {
                cJSON_AddStringToObject(Node, "IPAddress", sta->ip_addr);
            }

            if (strcmp(sta->ip6_addr, "::"))
            {
                cJSON_AddStringToObject(Node, "STAIPv6IPAddress", sta->ip6_addr);
            }

            cJSON_AddStringToObject(Node, "HostName", sta->hostname);
        }

        /* 暂无有效手段辨别设备类型，全部赋值PC */
        cJSON_AddStringToObject(Node, "STAType", "PC");

        cJSON_AddItemToArray(Devices, Node);
    }

    // 构造data
    cJSON *mdata = cJSON_CreateObject();
    cJSON_AddItemToObject(mdata, "Devices", Devices);
    cJSON_AddNumberToObject(mdata, "STANumber", sta_list.len);
    cJSON_AddItemToObject(jsonSend, "data", mdata);

    /*************** 下挂设备信息     *********************/
    _print_cJSON(jsonSend);
    ret = interface_data_report("if5", jsonSend);
    cJSON_Delete(jsonSend);
    jsonSend = NULL;

    DBG_PRINT("%s %d:IF5_event_STAstatus Success ret:%d\n", __FUNCTION__, __LINE__, ret);
    if (ret != 0)
    {
        DBG_PRINT("%s %d:IF5_event_STAstatus failed\n", __FUNCTION__, __LINE__);
        LogWrite(ERROR, "%s %d: %s", __FUNCTION__, __LINE__, "IF5_event_STAstatus failed");
    }
    return ret;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-12-29 16:51:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-29 16:51:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    
    return 0;
}
