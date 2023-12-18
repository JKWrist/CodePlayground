#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2023-10-24 10:45:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/


/****************************************************************
 *  函数名称：
 *  创建日期：2023-10-24 10:45:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/


/****************************************************************
 *  函数名称：main
 *  创建日期：2023-10-24 10:45:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char str_buf1[32]= {0};
	char cmd_buf1[64] = "cat ./while.sh | grep bbb";
	FILE *fp1 = popen(cmd_buf1, "r");
	if (NULL != fp1)
	{
		(void)fgets(str_buf1, sizeof(str_buf1), fp1);
		printf("aaa222 %s\n", str_buf1);
		pclose(fp1);

		if(strstr(str_buf1, "province_feature_ver"))
		{
			char str_buf2[12]= {0};
			char cmd_buf2[128] = "cat /config/work/lastgood.xml | grep -o 'Value Name=\"ulModeType\" Value=\"[^\"]*\"' | awk -F'Value=\"' '{print $2}'";
			FILE *fp2 = popen(cmd_buf2, "r");
			if (NULL != fp2)
			{
				(void)fgets(str_buf2, sizeof(str_buf2), fp2);
				printf("aaa222 %s\n", str_buf2);
				pclose(fp2);
			}
			
			int i_mode = atoi(str_buf2);
			printf("aaa222 %d\n", i_mode);

			if(i_mode)
			{
				printf("br0_mac.sh to_router\n");
			}
			else
			{
				printf("br0_mac.sh to_bridge\n");
			}
		}

	}
	return 0;
}
