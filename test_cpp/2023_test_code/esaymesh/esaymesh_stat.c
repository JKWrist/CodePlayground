#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define UPLINK_STATE "/tmp/esaymesh_uplink_state"

enum
{
	LAN_CONNECT               = 0,
	ESAY_MESH_UPLINK_WIRELESS = 1,
};

/****************************************************************
 *  函数名称：esaymesh_uplink
 *  创建日期：2023-10-17 16:43:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int esaymesh_uplink()
{
	FILE *fd = NULL;
	char input[64] = {0};

	fd = fopen(UPLINK_STATE, "r");
	if (NULL == fd)
	{
		return LAN_CONNECT;
	}

	if (NULL == fgets(input, sizeof(input), fd))
	{
		printf("fgets internal error!! %s %d\n", __func__,__LINE__);
		return LAN_CONNECT;
	}

	if (strstr(input, "eth") && strstr(input, "vap"))
	{
		if (strstr(input, "eth") < strstr(input, "vap"))
		{
			return ESAY_MESH_UPLINK_WIRELESS;
		}
		else
		{
			return LAN_CONNECT;
		}
	}

	return LAN_CONNECT;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-10-17 15:32:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	// char c_str[256] = {0};
	// sprintf(c_str, "mkdir -p /tmp/esaymesh;echo \"change uplink dev %s to %s\" > %s", "eth", "vap", UPLINK_STATE);
	// system(c_str);

	printf("%d\n", esaymesh_uplink());
	return 0;
}
