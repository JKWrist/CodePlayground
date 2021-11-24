#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include "wrap.h"

int main()
{
    int sock = tcp4bind(8888, NULL);
    printf("sock %d\n", sock);

    //设置端口复用
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    int ret = accept(sock, NULL, NULL);
    printf("ret %d\n", ret);
    if(ret < 0)
        perror("accept");
    
    while (1)
    {
        sleep(20);
    }
    return 0;
}
