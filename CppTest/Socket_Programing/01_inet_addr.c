#include <stdio.h>
#include <arpa/inet.h>

//网络编程部分放最少的头文件，缺什么加什么


int main()
{
    //函数原型
    // in_addr_t
    // inet_addr(const char *cp);

    char * addr1 = "1.2.3.4";
    char * addr2 = "2.3.4.256";


    unsigned long conv_addr = inet_addr(addr1);
    if (INADDR_NONE == conv_addr)
    {
        printf("Error occured\n");
    }
    else
    {
        printf("Network order integer addr : %#lx\n", conv_addr);
    }
    
    conv_addr = inet_addr(addr2);
    if (INADDR_NONE == conv_addr)
    {
        printf("Error occured\n");
    }
    else
    {
        printf("Network order integer addr : %#lx\n", conv_addr);
    }
}