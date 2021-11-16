#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>

void test01()
{
    //概念， 大端 ： 高端地存放低位数据
    
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    net_port = htons(host_port);
    net_addr = htonl(host_addr);

    printf("port Host ordered : %#x \n", host_port);
    printf("port Net ordered : %#x \n", net_port);

    printf("address Host ordered : %#lx \n", host_addr);
    printf("address Net ordered : %#lx \n", net_addr);

    // Host ordered port : 0x1234 
    // Net ordered port : 0x3412 
    // Host ordered address : 0x12345678 
    // Net ordered address : 0x78563412
}

// 1、联合union是一个能在同一个存储空间存储不同类型数据的类型；
// 2、同一内存段可以用来存放几种不同类型的成员，但每一瞬时只有一种起作用；

union
{
    short s;
    char c[sizeof(short)];
} un2;

union{
    int s;
    char c[sizeof(int)];
}un4;

void test02()
{
    printf("[%d][%d][%d]\n", sizeof(short), sizeof(int), sizeof(long int));
    
    //测试short类型
    un2.s = 0x0102; //0x0102 =  16*16 + 2
    printf("array after %p\n", &un2.c[1]);
    printf("array before %p\n", &un2.c[0]);
    printf("array after - before = %d\n", &un2.c[1] - &un2.c[0]);

    //后面的地址是高地址，高地址存放高位数据是小端
    printf("0x0102  01 是高位数据， 02是低位数据\n");
    printf("低位地址数据：%d, 高位地址数据%d, %d\n", un2.c[0], un2.c[1], un2.s);
}




/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-14 15:51:08
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //test01();

    test02();

    return 0;
}
