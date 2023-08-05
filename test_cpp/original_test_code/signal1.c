#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int a = 0;

void test_a()
{
    a++;
    sleep(3);
    printf("a = %d\n", a);
    pid_t process_id;
    pid_t p_process_id;
    process_id = getpid();    //返回当前进程的进程ID
    p_process_id = getppid(); //返回调父进程的进程ID
    printf("当前进程的进程ID：%d %s %d\n", process_id, __FUNCTION__, __LINE__);
    printf("父进程的进程ID：%d %s %d\n", p_process_id, __FUNCTION__, __LINE__);
}

int main()
{

    pid_t process_id;
    pid_t p_process_id;
    process_id = getpid();    //返回当前进程的进程ID
    p_process_id = getppid(); //返回调父进程的进程ID
    printf("当前进程的进程ID：%d %s %d\n", process_id, __FUNCTION__, __LINE__);
    printf("父进程的进程ID：%d %s %d\n", p_process_id, __FUNCTION__, __LINE__);

    signal(SIGUSR1, test_a);
    while (1)
    {
    };
}