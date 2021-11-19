#ifndef __WRAP_C__
#define __WRAP_C__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

//此处应该使用最少的头文件放在这里，否则后面每一个
//引用此处头文件的地方在预处理的时候都会将头文件展开

void perr_exit(const char *s);

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr);
int Bind(int fd, const struct sockaddr *sa, socklen_t salen);
int Connect(int fd, const struct sockaddr *sa, socklen_t salen);

int Listen(int fd, int backlog);
int Socket(int family, int type, int protocol);
ssize_t Read(int fd, void *ptr, ssize_t nbytes);
ssize_t Write(int fd, const void *ptr, ssize_t ntypes);
int Colse(int fd);

ssize_t Readn(int fd, void *vptr, size_t n);
ssize_t Writen(int fd, const void *vptr, size_t n);

ssize_t my_read(int fd, char *ptr);
ssize_t Readline(int fd, void *vptr, size_t maxlen);
int tcp4bind(short port, const char *IP);

#endif //__WRAP_C__