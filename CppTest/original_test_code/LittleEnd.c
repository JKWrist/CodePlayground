#include <stdio.h>
#include <arpa/inet.h>

int main()
{
    union
    {
        short value;
        char union_bytes[sizeof(short)];
    } test;

    test.value = 0x0102;

    printf("sizeof(test) %d \n", sizeof(test));
    printf("sizeof(short) %d \n", sizeof(short));
    printf("test.value %d \n", test.value);
    printf("test.union_bytes %s \n", test.union_bytes);
    
    if ((test.union_bytes[0] == 1) && (test.union_bytes[1] == 2))
    {
        printf("nig end\n");
    }
    else if ((test.union_bytes[0] == 2) && (test.union_bytes[1] == 1))
    {
        printf("little end\n");
    }

    unsigned short host_port = 0x1234;
    unsigned short net_port;

    net_port = htons(host_port);
    printf("Network ordered port : %#x\n", net_port);
    printf("Host ordered port : %#x\n", host_port);
    return 0;

}