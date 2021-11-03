#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


// kill -l

//1、signal 标识
/*
 1) SIGHUP	 2) SIGINT	 3) SIGQUIT	 4) SIGILL	 5) SIGTRAP
 6) SIGABRT	 7) SIGBUS	 8) SIGFPE	 9) SIGKILL	10) SIGUSR1
11) SIGSEGV	12) SIGUSR2	13) SIGPIPE	14) SIGALRM	15) SIGTERM
16) SIGSTKFLT	17) SIGCHLD	18) SIGCONT	19) SIGSTOP	20) SIGTSTP
21) SIGTTIN	22) SIGTTOU	23) SIGURG	24) SIGXCPU	25) SIGXFSZ
26) SIGVTALRM	27) SIGPROF	28) SIGWINCH	29) SIGIO	30) SIGPWR
31) SIGSYS	34) SIGRTMIN	35) SIGRTMIN+1	36) SIGRTMIN+2	37) SIGRTMIN+3
38) SIGRTMIN+4	39) SIGRTMIN+5	40) SIGRTMIN+6	41) SIGRTMIN+7	42) SIGRTMIN+8
43) SIGRTMIN+9	44) SIGRTMIN+10	45) SIGRTMIN+11	46) SIGRTMIN+12	47) SIGRTMIN+13
48) SIGRTMIN+14	49) SIGRTMIN+15	50) SIGRTMAX-14	51) SIGRTMAX-13	52) SIGRTMAX-12
53) SIGRTMAX-11	54) SIGRTMAX-10	55) SIGRTMAX-9	56) SIGRTMAX-8	57) SIGRTMAX-7
58) SIGRTMAX-6	59) SIGRTMAX-5	60) SIGRTMAX-4	61) SIGRTMAX-3	62) SIGRTMAX-2
63) SIGRTMAX-1	64) SIGRTMAX
*/

//2、signal 详细信息

// man 7 signal
// SIGNAL(7)                  Linux Programmer's Manual                  SIGNAL(7)

// NAME
//        signal - overview of signals

// DESCRIPTION
//        Linux  supports  both POSIX reliable signals (hereinafter "standard sig‐
//        nals") and POSIX real-time signals.

//    Signal dispositions
//        Each signal has a current disposition, which determines how the  process
//        behaves when it is delivered the signal.

//        The  entries  in  the  "Action"  column  of the tables below specify the
//        default disposition for each signal, as follows:

//        Term   Default action is to terminate the process.

//        Ign    Default action is to ignore the signal.

//        Core   Default action is to terminate the process  and  dump  core  (see
//               core(5)).

//        Stop   Default action is to stop the process.

//        Cont   Default  action  is  to  continue  the process if it is currently
//               stopped.

//3、计算在内核区用户态运行时间

// time ./a.out 运行时间 用户态时间 内核态时间
// real    0m1.010s
// user    0m0.207s
// sys     0m0.077s

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-26 21:36:21
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    alarm(1);
    int i = 0;

    while(1)
    {
        printf("[%d]", i++);
    }
    return 0;
}
