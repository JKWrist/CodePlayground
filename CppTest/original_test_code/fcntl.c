#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <arpa/inet.h>
int main(int argc, char *argv[]) 
{
	int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	
	int flags = fcntl(socket, F_GETFL, 0);
	/* 设置为非阻塞*/
	if (fcntl(serv_sock, F_SETFL, flags | O_NONBLOCK) < 0)
	{
	/* Handle error */
	}
	/* 设置为阻塞 */
	if ((flags = fcntl(serv_sock, F_SETFL, 0)) < 0)
	{
	/* Handle error */
	}
}