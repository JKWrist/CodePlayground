#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MPCTL_DBG(fmt, ...) fprintf(stderr, "<%s:%d> "fmt, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define SYS_CLASS_LEDS       "gpio"
#define REA_LED_STATE_FILE   "/sys/class/gpio/gpio36/value"
#define GREEN_LED_STATE_FILE "/sys/class/gpio/gpio41/value"

typedef enum led_state
{
    green_off          = 0,
    green_on           = 1,
    green_fast_blink   = 2,
    red_on             = 3,
    red_off            = 4,
    green_slow_blink   = 5,
    red_slow_blink     = 6,
    red_fast_blink     = 7,
} LED_STATE_T;

/****************************************************************
    设置指示灯相关接口:
红灯点亮: echo 3 > gpio
红灯熄灭: echo 4 > gpio
红灯快闪: echo 7 > gpio
红灯慢闪: echo 6 > gpio


绿灯点亮: echo 1 > gpio
绿灯熄灭: echo 0 > gpio
绿灯快闪: echo 2 > gpio
绿灯慢闪: echo 5 > gpio

    获取指示灯状态
红灯状态：cat /sys/class/gpio/gpio36/value  0亮，1灭
绿灯状态：cat /sys/class/gpio/gpio41/value  0亮，1灭

cat gpio
如果值不是2和5  表示绿灯不闪烁
如果值不是6和7  表示红灯不闪烁
******************************************************************/


/****************************************************************
 *  函数名称：get_led_brightness
 *  创建日期：2022-04-09 17:33:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
static int get_led_state()
{
    char path[64] = "./gpio";
    char line[12];
    FILE* fp = NULL;
    char* pstr = NULL;

    fp = fopen(path, "r");
    if (NULL == fp)
    {
        MPCTL_DBG("open file(%s) fail,errno(%d)\n", path, errno);
        return 0;
    }

    pstr = fgets(line, sizeof(line), fp);
    fclose(fp);
    return atoi(pstr);
}

/****************************************************************
 *  函数名称：set_led_state
 *  创建日期：2022-04-09 17:34:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
static void set_led_state(LED_STATE_T st)
{
    MPCTL_DBG("%s, st : %d\n",__FUNCTION__, st);
    char path[64] = "./gpio";
    FILE* fp = fopen(path, "w");
    if (NULL == fp)
    {
        MPCTL_DBG("open file(%s) fail,errno(%d)\n", path, errno);
        return;
    }
    fputc(st + 48, fp);  //ASCII数字从48开始，加enum 即可转换为数字
    fclose(fp);
}


/****************************************************************
 *  函数名称：usage
 *  创建日期：2022-04-09 17:36:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void usage(void)
{
    printf("亮灯                  \n");
    printf("mpctl red on          \n");   //红灯亮
    printf("mpctl green on		  \n");   //绿灯亮
    printf("                      \n");
    printf("灭灯                  \n");
    printf("mpctl red off         \n");   //灭红灯
    printf("mpctl green off       \n");   //灭绿灯
    printf("                      \n");
    printf("闪灯                  \n");
    printf("mpctl red slow_blink  \n");   //红灯慢闪
    printf("mpctl red fast_blink  \n");   //红灯快闪
    printf("mpctl green slow_blink\n");   //绿灯慢闪
    printf("mpctl green fast_blink\n");   //绿灯快闪
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-11 16:11:43
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int time = 0;
    switch(argc)
    {
        case 3:
            if (0 == strcmp(argv[1], "red"))
            {
                if (0 == strcmp(argv[2], "on"))
                {
                    set_led_state(red_on);
                    break;
                }
                if (0 == strcmp(argv[2], "off"))
                {
                    set_led_state(red_off);
                    break;
                }
                if (0 == strcmp(argv[2], "slow_blink"))
                {
                    set_led_state(red_slow_blink);
                    break;
                }
                if (0 == strcmp(argv[2], "fast_blink"))
                {
                    set_led_state(red_fast_blink);
                    break;
                }
            }
            
            if (0 == strcmp(argv[1], "green"))
            {
                if (0 == strcmp(argv[2], "on"))
                {
                    set_led_state(green_on);
                    break;
                }
                if (0 == strcmp(argv[2], "off"))
                {
                    set_led_state(green_off);
                    break;
                }
                if (0 == strcmp(argv[2], "slow_blink"))
                {
                    set_led_state(green_slow_blink);
                    break;
                }
                if (0 == strcmp(argv[2], "fast_blink"))
                {
                    set_led_state(green_fast_blink);
                    break;
                }
            }
            goto arg_err_rtn;
        default:
            goto arg_err_rtn;
    };
    return 0;

arg_err_rtn:
    usage();
    exit(1);
}