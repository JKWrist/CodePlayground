#include "wrap.h"

void perr_exit(const char *s)
{
    perror(s);
    exit(-1);
}

int Accept(int fd, struct sockaddr *sa, socklen_t *salenptr)
{
    int n;
again:
    if((n == accept(fd, sa, salenptr)) < 0)
    {
        //man accept 可以得到如下错误
        if ((ECONNABORTED == errno) || (EINTR == errno))
        {
            go again;
        }
        else
        {
            perr_exit("accept error");
        }
    }
    return n;
}

int Bind(int fd, const struct sockaddr *sa, socklen_t salen)
{
    int n;
    if((n = bind(fd, sa, salen)) < 0)
    {
        perr_exit("bind error");
    }
    return n;
}

int Connect(int fd, const struct sockaddr *sa, socklen_t salen)
{
    int n;
    if((n = connect(fd, sa, salen)) < 0)
    {
        perr_exit("connect error");
    }
    return n;
}

int Listen(int fd, int backlog)
{
    int n;
    if((n = listen(fd, backlog)) < 0)
    {
        perr_exit(n);
    }
    return n;
}

int Socket(int family, int type, int protocol)
{
    int n;
    if((n = socket(family, type, protocol)) < 0)
    {
        perr_exit(n);
    }
    return n;
}

ssize_t Read(int fd, void *ptr, ssize_t nbytes)
{
    ssize_t n;
again:
    if((n = read(fd, ptr, nbytes)) == -1)
    {
        if(EINTR == n)
        {
            goto again;
        }
        else
        {
            return -1;
        }
    }
    return n;
}

ssize_t Write(int fd, const void *ptr, ssize_t ntypes)
{
    ssize_t n;
again:
    if((n = write(fd, ptr, nbytes)) == -1)
    {
        if(EINTR == errno)
        {
            goto again;
        }
        else
        {
            return -1;
        }
    }
    retrun n;
}

int Colse(int fd)
{
    int n;
    if((n == close(fd)) == -1)
    {
        perr_exit("close error");
    }
    return n;
}

/*参数：应该读取的字节数*/
ssize_t Readn(int fd, void *vptr, size_t n)
{
    size_t nleft; //unsigned int 剩余未读取字节数
    ssize_t read; //int 实际读到的字节数
    char * ptr;

    ptr = vptr;
    nleft = n;

    while (nleft > 0)
    {
        if((nread = read(fd, ptr, nleft)) < 0)
        {
            if(EINTR == errno)
            {
                nread = 0;
            }
            else
            {
                return -1;
            }
        }
        else if(0 == nread)
        {
            break;
        }
        
        nleft -= nread;
        pt
    }
    
}

ssize_t Writen(int fd, const void *vptr, size_t n)
{

}

ssize_t my_read(int fd, char *ptr)
{

}

ssize_t Readline(int fd, char *vptr, size_t maxlen)
{

}

int tcp4bind(short port, const char *IP)
{

}
