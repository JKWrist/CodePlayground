#include <stdio.h>
#include <signal.h>
#include <errno.h>
void sig_int(int);
void pr_mask(const char *);

int main(int argc, char *argv[])
{

    setbuf(stdout, NULL); //close buffer
    pr_mask("before catching signal ,mask sig  :");

    if (signal(SIGINT, sig_int) == SIG_ERR)
        oops("signal");

    //keep loop to catch signal interuption
    while (1)
        //	pause();
        sleep(3);

    pr_mask("end catching signal ,mask sig  :");

    return 0;
}

//signal handler
void sig_int(int signo)
{
    pr_mask("in signal handler:");
}

void oops(void *msg)
{
    perror(msg);
    exit(1);
}

void pr_mask(const char *str)
{
    sigset_t set;
    int errno_save; //get the pre errno

    errno_save = errno;

    if (sigprocmask(0, NULL, &set) == -1)
        oops(" sigmask");
    else
    {
        printf("\n%s", str);
        if (sigismember(&set, SIGQUIT))
            printf(" SIGQUIT");
        if (sigismember(&set, SIGINT))
            printf(" SIGINT");
        if (sigismember(&set, SIGUSR1))
            printf(" SIGUSR1");
        if (sigismember(&set, SIGALRM))
            printf(" SIGALRM");
    }
    errno = errno_save;
}