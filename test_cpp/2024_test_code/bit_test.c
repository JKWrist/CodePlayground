#include <stdio.h>

// 获取指定位的开关状态
int get_bit(int num, int bit_index)
{
    return (num >> bit_index) & 1;
}

// 配置指定位的开关状态
int set_bit(int num, int bit_index, int value)
{
    int mask = 1 << bit_index;
    num &= ~mask; // 先关闭指定位
    if (value)
    {
        num |= mask; // 如果要设置的值为1，则开启指定位
    }
    return num;
}

int test1()
{
    int config = 0b1010; // 二进制表示每位的开关状态为 1010
    int bit_index = 4;
    printf("第 %d 位的配置为: %d\n", bit_index, get_bit(config, bit_index)); // 获取第2位的配置
    config = set_bit(config, bit_index, 1); // 将第2位的配置设置为1
    printf("更新后的配置为: %d\n", config);
}

int test2()
{
	int num1 = 10;
    printf("更新后的配置为: %d\n", num1>>0);
    printf("更新后的配置为: %d\n", num1>>1);
    printf("更新后的配置为: %d\n", num1>>2);
    printf("更新后的配置为: %d\n", num1>>3);	
}

int main()
{
	test2();
    return 0;
}
