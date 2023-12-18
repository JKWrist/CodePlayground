#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int g_url_filter_debug = 0; // 初始状态下关闭调试模式

int main()
{
    FILE *configFile = fopen("./url_filter_debug.config", "r");
    if (configFile != NULL)
    {
        fscanf(configFile, "%d", &g_url_filter_debug); // 从配置文件中读取调试标志
        fclose(configFile); // 关闭配置文件
    }
    else
    {
        printf("无法打开配置文件，使用默认设置：调试模式关闭\n");
    }

    if (g_url_filter_debug == 1)
    {
        printf("调试模式已启用\n");
    }
    else
    {
        printf("调试模式已关闭\n");
    }

    return 0;
}