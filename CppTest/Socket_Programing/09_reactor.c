//reactor反应堆简单版本
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#define _BUF_LEN_ 1024
#define _EVENT_SIZE_ 1024

//全局epoll树
int gepfd = 0;

//事件驱动结构体
typedef struct xevent
{
	int fd;
	int events;
	void * arg;
	void (*call_back)(int fd, int events, void * arg);
	char buf[1024];
	int buflen;
	int epfd;
} xevent;

xevent myevents[_EVENT_SIZE_ + 1];
void readData(int fd, int evnets, void * arg);

/****************************************************************
 *  函数名称：添加事件
 *  创建日期：2022-02-02 21:55:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventadd(int fd, int events, void * arg, void (*call_back)(int , int , void *), xevent * ev)
{
	printf("begin call : %s fd : %d\n", __FUNCTION__, fd);

	ev->fd = fd;
	ev->events = events;
	//ev->arg = arg; 代表结构体自己，可以通过arg得到结构体的所有信息
	ev->call_back = call_back;

	struct epoll_event epv;
	epv.events = events;
	epv.data.ptr = ev;							//核心思想
	epoll_ctl(gepfd, EPOLL_CTL_ADD, fd, &epv);	//上树
}

/****************************************************************
 *  函数名称：修改事件
 *  创建日期：2022-02-03 18:06:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventset(int fd, int events, void * arg, void (*call_back)(int, int, void *), xevent * ev)
{
	printf("begin call %s\n", __FUNCTION__);

	ev->fd = fd;
	ev->events = events;
	//ev->arg = arg;
	ev->call_back = call_back;

	struct epoll_event epv;
	epv.events = events;
	epv.data.ptr = ev;
	epoll_ctl(gepfd, EPOLL_CTL_MOD, fd, &epv);
}

/****************************************************************
 *  函数名称：删除事件
 *  创建日期：2022-02-03 18:11:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void eventdel(xevent * ev, int fd, int events)
{
	printf("begin call%s\n", __FUNCTION__);

	//对于一个事件驱动结构体进行清空
	ev->fd = 0;
	ev->events = 0;
	//ev->arg = NULL;
	ev->call_back = NULL;
	memset(ev->buf, 0x00, sizeof(ev->buf));
	ev->buflen = 0;

	struct epoll_event epv;
	epv.events = events;
	epv.data.ptr = NULL;
	epoll_ctl(gepfd, EPOLL_CTL_DEL, fd, &epv);	//下树
}

/****************************************************************
 *  函数名称：发送数据
 *  创建日期：2022-02-03 18:19:01
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void sendData(int fd, int evnets, void *arg)
{
	printf("begin call %s\n", __FUNCTION__);

	xevent * ev = arg;
	write(fd, ev->buf, ev->buflen);
	eventset(fd, EPOLLIN, arg, readData, ev);
}

/****************************************************************
 *  函数名称：读取数据
 *  创建日期：2022-02-03 18:29:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void readData(int fd, int evnets, void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	xevent * ev = arg;
	ev->buflen = read(fd, ev->buf, sizeof(ev->buf));
	if(ev->buflen > 0)
	{
		//evnetset(int fd, int events, void * arg, void (*call_back)(int, int, void *), xevent * ev)
		eventset(fd, EPOLLOUT, arg, sendData, ev);
	}
	else if(0 == ev->buflen)
	{
		close(fd);
		eventdel(ev, fd, EPOLLIN);
	}
}

/****************************************************************
 *  函数名称：新连接处理
 *  创建日期：2022-02-03 18:46:05
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void initAccept(int fd, int events, void * arg)
{
	printf("begin call %s\n", __FUNCTION__);

	struct sockaddr_in addr;
	socklen_t len = sizeof(addr);
	
	//一会调试的时候，需要注意查看不同
	int cfd = accept(fd, (struct sockaddr*)&addr, &len); //是否会阻塞，这个地方不会阻塞
	printf("cfd = %d\n", cfd);

	//查找myevents 数组中可用的位置
	int i;
	for(i = 0; i < _EVENT_SIZE_; i++)
	{
		if(0 == myevents[i].fd)
		{
			break;
		}
	}

	//设置读事件
	//eventadd(int fd, int events, void * arg, void (*call_back)(int , int , void *), xevent * ev)
	eventadd(cfd, EPOLLIN, &myevents[i], readData, &myevents[i]);
}

int main()
{
	//创建socket
	int lfd = socket(AF_INET, SOCK_STREAM, 0);

	//端口复用
	int opt = 1;
	setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	//绑定
	struct sockaddr_in servaddr;
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8888);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	//监听
	listen(lfd, 128);
	printf("lfd = %d\n", lfd);

	//创建epoll树根节点
	gepfd = epoll_create(1024);
	printf("gepfd = %d\n", gepfd);

	struct epoll_event events[1024];

	//添加初始监听事件，将文件描述符上树
	eventadd(lfd, EPOLLIN, &myevents[_EVENT_SIZE_], initAccept, &myevents[_EVENT_SIZE_]);

	while(1)
	{
		int nready = epoll_wait(gepfd, events, 1024, -1);
		if(nready < 0)
		{
			perror("epoll wait error\n");
		}
		else if(nready > 0)
		{
			for (int i = 0; i < nready; i++)
			{
				xevent *xe = events[i].data.ptr; //取得ptr指向的结构体地址
				printf("fd = %d\n", xe->fd);
			
				if(xe->events & events[i].events)
				{
					xe->call_back(xe->fd, xe->events, xe); //调用事件对应的回调
				}
			}
		}
	}
	
	//关闭监听文件描述符
	close(lfd);

	return 0;
}
