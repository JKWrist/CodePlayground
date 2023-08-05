// epoll 基于非阻塞I/O事件驱动

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_EVENTS 1024 								// 监听上限数
#define BUFLEN 	   4096

void recvData(int fd, int events, void * arg);
void sendData(int fd, int events, void * arg);

//事件驱动结构体封装
struct myevent_s
{
	int fd;												//要监听的文件描述符
	int events;											//对应的监听事件
	void * arg;											//泛型参数
	void (*call_back)(int fd, int events, void * arg); 	//回调函数
	int status;											//是否在监听：1->在红黑树上(监听) 0->不在
	char buf[BUFLEN];									//发送或者接收的缓冲区,防止乱序
	int len;			
	long last_active;									//记录每次加入红黑树 g_efd 的时间值
};

int g_efd;												//全局变量，保存epoll_create返回的文件描述符
int g_lfd;												//全局变量，保存监听的文件描述符
struct myevent_s g_events[MAX_EVENTS + 1]; 				//事件驱动结构体数组，+1---> listen fd 

/****************************************************************
 *  函数名称：将结构体 myevent_s 成员变量初始化
 *  创建日期：2022-02-05 17:25:38
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventset(struct myevent_s *ev, int fd, void (*call_back)(int , int , void *), void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	ev->fd = fd;
	ev->events = 0;
	ev->arg = arg;
	ev->call_back = call_back;
	ev->status = 0;
	ev->last_active = time(NULL);
}

/****************************************************************
 *  函数名称：向epoll监听的红黑树添加一个文件描述符
 *  创建日期：2022-02-05 17:25:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventadd(int efd, int events, struct myevent_s * ev)
{
	printf("begin call %s\n", __FUNCTION__);

	//修改事件驱动结构体
	ev->events = events;

	//为 epoll_ctl 初始化 epoll_event 结构体
	struct epoll_event epv = {0, {0}};
	epv.data.ptr = ev;
	epv.events = events;		//EPOLL_IN 或 EPOLL_OUT

	int op;
	if(1 == ev->status)
	{										//已经在红黑树中
		op = EPOLL_CTL_MOD;					//修改其属性
	}
	else
	{										//不在红黑树中
		op = EPOLL_CTL_ADD;					//将其加入红黑树 g_efd, 并将status置为1
		ev->status = 1;
	}

	if(epoll_ctl(efd, op, ev->fd, &epv) < 0)		//实际添加，修改
	{
		printf("event add failed [fd = %d], events [%d]\n", ev->fd, events);
	}
	else
	{
		printf("event add OK [fd = %d], op = [%d], events [%d]\n", ev->fd, op, events);
	}
}

/****************************************************************
 *  函数名称：从 epoll 监听的 红黑树中删除一个 文件描述符
 *  创建日期：2022-02-05 18:17:13
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventdel(int efd, struct myevent_s * ev)
{
	printf("begin call %s\n", __FUNCTION__);

	struct epoll_event epv = {0, {0}};
	if(ev->status != 1)								//不在红黑树上
	{
		return;
	}

	epv.data.ptr = ev;
	
	//事件驱动结构体
	ev->status = 0;									//修改状态
	epoll_ctl(efd, EPOLL_CTL_DEL, ev->fd, &epv);	//从红黑树 efd 上将 ev->fd 摘除
}

/****************************************************************
 *  函数名称：当有文件描述符就绪，epoll返回， 调用该函数与客户端建立链接
 *  			当监听文件描述符，发生读事件的时候被调用
 *  创建日期：2022-02-05 18:24:29
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void acceptConn(int lfd, int events, void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	struct sockaddr_in cin;
	socklen_t len = sizeof(cin);
	int cfd = accept(lfd, (struct sockaddr *)&cin, &len);
	int i = 0;
	
	//使用do_while语句是为了避免使用goto语句
	do
	{
		for(i = 0; i < MAX_EVENTS; i++)		//从全局数组g_events中找到一个空闲元素
		{
			if(0 == g_events[i].status)			//类似于select中找值为-1的元素
			{
				break;							//跳出	for
			}
		}

		if(i == MAX_EVENTS)
		{
			printf("%s: max connect limit[%d]\n", __func__, MAX_EVENTS);
			break; 								//避免goto，跳出do while(0) 不执行后续代码
		}

		//将cfd设置为非阻塞
		int flags = 0;
		flags = fcntl(cfd, F_GETFL, 0);
		flags |= O_NONBLOCK;

		if((flags = fcntl(cfd, F_SETFL, flags)) < 0)
		{
			printf("%s : fcntl nonblocking failed, %s\n", __func__, strerror(errno));
			break;
		}

		//给cfd设置一个 myevent_s 结构体，回调函数 设置为 recvData
		//eventset(struct myevent_s *ev, int fd, void (*call_back)(int , int , void *), void * arg)
		eventset(&g_events[i], cfd, recvData, &g_events[i]);

		//将cfd添加到红黑树g_efd中，监听读事件
		// eventadd(int efd, int events, struct myevent_s * ev)
		eventadd(g_efd, events, &g_events[i]);
	}while(0);

	printf("new connect [%s:%d][time:%ld], pos[%d]",
			inet_ntoa(cin.sin_addr), ntohs(cin.sin_port), g_events[i].last_active, i);
}


/****************************************************************
 *  函数名称：通信文件描述符发生读事件的时候被调用 接收数据的回调函数
 *  创建日期：2022-02-06 18:15:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void recvData(int fd, int events, void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	int len;
	struct myevent_s *ev = (struct myevent_s *)arg;

	//读取客户端发来的数据
	memset(ev->buf, 0x00, sizeof(ev->buf));
	len = read(fd, ev->buf, sizeof(ev->buf)); //读文件描述符，数据存入myevent_s成员buf中

	eventdel(g_efd, ev);

	if(len > 0 )
	{
		ev->len = len;
		ev->buf[len] = '\0';
		printf("C[%d]:%s\n", fd, ev->buf);

		eventset(ev, fd, sendData, ev);
		eventadd(g_efd, EPOLLOUT, ev);
	}
	else if(len == 0)
	{
		close(ev->fd);
		//ev - g_events 可以得到偏移元素位置
		printf("[fd = %d] pos = %ld, closed\n", fd, ev - g_events);
	}
	else
	{
		close(ev->fd);
		printf("read [fd = %d] errno [%d] : %s\n", fd, errno, strerror(errno));
	}
}

/****************************************************************
 *  函数名称：通信文件描述符发生写事件时调用
 *  创建日期：2022-02-06 18:25:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void sendData(int fd, int events, void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	int len;
	struct myevent_s *ev = (struct myevent_s *)arg;

	//将小写转换为大写发送给客户端
	int i = 0;
	for(i = 0; i < ev->len; i++)
	{
		ev->buf[i] = toupper(ev->buf[i]);
	}

	//发送数据给客户端
	len = write(fd, ev->buf, ev->len);
	if(len > 0)
	{
		printf("send[fd = %d]--->[%d]:[%s]\n", fd, len, ev->buf);
		eventdel(g_efd, ev);
		eventset(ev,fd, recvData, ev);
		eventadd(g_efd, EPOLLIN, ev);
	}
}

/****************************************************************
 *  函数名称：创建并初始化 监听socket lfd
 *  创建日期：2022-02-06 18:37:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void initListenSocket()
{
	printf("begin call %s\n", __FUNCTION__);

	//创建socket
	g_lfd = socket(AF_INET, SOCK_STREAM, 0);

	//对事件驱动结构体进行赋值
	//void eventset(struct myevent_s *ev, int fd, void (*call_back)(int , int , void *), void * arg)
	eventset(&g_events[MAX_EVENTS], g_lfd, acceptConn, &g_events[MAX_EVENTS]);

	//将监听文件描述符上树
	//void eventadd(int efd, int events, struct myevent_s * ev)
	eventadd(g_efd, EPOLLIN, &g_events[MAX_EVENTS]);

	//绑定
	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8888);
	bind(g_lfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	listen(g_lfd, 128);
}

int main()
{
	g_efd = epoll_create(20);  //创建红黑树，返回给全局变量 g_efd

	if(g_efd < 0)
	{
		perror("create epoll error");
	}

	//socket bind listen将文件描述符上树
	initListenSocket();

	struct epoll_event events[MAX_EVENTS+1];
	int checkpos = 0, i;
	while(1)
	{
		//超时验证，每次测试100个连接，不测试listenfd，当客户端60秒内没有和服务器进行通信
		//则关闭此客户端链接

		long now = time(NULL);	//当前时间

		//一次循环测100个，使用checkpos控制检测对象
		for(i = 0; i < 100; i++, checkpos++)
		{
			if(checkpos == MAX_EVENTS)
			{
				checkpos = 0;
			}

			if(g_events[checkpos].status != 1)
			{
				continue;
			}

			long duration = now - g_events[checkpos].last_active;  //客户端不活跃的时间

			if(duration >= 60)
			{
				close(g_events[checkpos].fd);				//关闭客户端链接
				printf("[fd = %d] timeout\n", g_events[checkpos].fd);
				eventdel(g_efd, &g_events[checkpos]);
			}
		}

		//监听红黑树g_efd，将满足的时间的文件描述符添加到events数组中， 1秒没有时间满足，返回0
		int nfd = epoll_wait(g_efd, events, MAX_EVENTS, 1000);
		
		printf("epoll_wait return %d\n", nfd);

		if(nfd < 0)
		{
			printf("epoll wait error, exit\n");
			break;
		}

		for(i = 0; i < nfd; i++)
		{
			//使用自定义结构体myevent_s类型指针，接收联合体data的void * ptr成员
			struct myevent_s *ev = (struct myevent_s *)events[i].data.ptr;

			//读就绪事件, 对于监听事件和读取数据来说都是读事件
			if((events[i].events & EPOLLIN) && (ev->events & EPOLLIN))
			{
				//void (*call_back)(int fd, int events, void * arg);
				ev->call_back(ev->fd, events[i].events, ev);
			}

			//写就绪事件
			if((events[i].events & EPOLLOUT) && (ev->events & EPOLLOUT))
			{
				//void (*call_back)(int fd, int events, void * arg);
				ev->call_back(ev->fd, events[i].events, ev);
			}
		}
	}

	//关闭文件描述符
	close(g_efd);
	close(g_lfd);
}