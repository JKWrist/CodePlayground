#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>
#include <pthread.h>

void *thread_work(void *arg)
{
    int sock = *(int *)arg;
    char buf[1024];
    int len = 0;
    while(1)
    {   
        sleep(2);

        memset(buf, 0, sizeof(buf));
        int len = read(sock, buf, sizeof(buf));
        if(len  < 0)
        {
            continue;
        }

        printf("%s %d\n", buf, len); 
        
        for (int i = 0; i < len; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(sock, buf, len);
    }
}

int main()
{
    //int sock = tcp4bind(8888, NULL);
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    printf("sock %d\n", sock);

    //设置端口复用
    int opt = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(8888);

    bind(sock, (struct sockaddr *)&server, sizeof(server));

    listen(sock, 256);

    struct sockaddr_in client;
    socklen_t len = sizeof(client);

    int cfd;
    pthread_t threadID;

    while (1)
    {
        sleep(1);

        int cli_sock = accept(sock, (struct sockaddr *)&client, &len);

        printf("cli_sock %d\n", cli_sock);
        pthread_create(&threadID, NULL, thread_work, &cli_sock);

        if (cli_sock < 0)
        {
            perror("accept");
        }
    }

    return 0;
}
