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

void test02()
{

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


    return 0;
}
