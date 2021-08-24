#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
sigprocmask
�����������趨���ź����μ��ڵ��źŵĴ���ʽ(����������)��
�÷���
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
������
how������ָ���ź��޸ĵķ�ʽ������ѡ��������

SIG_BLOCK //�����źŵ��������Ρ�
SIG_UNBLOCK //�ӽ��������ｫ�ź�ɾ����
SIG_SETMASK //��set��ֵ�趨Ϊ�µĽ������Ρ�

set��Ϊָ���źż���ָ�룬�ڴ�רָ������źż�����������ȡ���ڵ�����ֵ���ɽ�����ΪNULL��
oldset��Ҳ��ָ���źż���ָ�룬�ڴ˴��ԭ�����źż���
����˵����
�ɹ�ִ��ʱ������0��ʧ�ܷ���-1��errno����ΪEINVAL��
*/
static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    signal(SIGQUIT, sig_quit); //��SIGQUIT�Ķ�����Ϊȱʡֵ
}

int main()
{
    sigset_t newmask;
    sigset_t oldmask;
    sigset_t pendmask;

    signal(SIGQUIT, sig_quit); //�ź�����׽��������׽��SIGQUIT����ת������ָ��sig_quit��ִ��

    while(1)
    {
        printf("SIGQUIT blocked\n");
        sigemptyset(&newmask);        //��ʼ���ź�����
        sigaddset(&newmask, SIGQUIT); //��SIGQUIT��ӵ��ź�������
        sigprocmask(SIG_BLOCK, &newmask, &oldmask); //��newmask�е�SIGQUIT�������������浱ǰ�ź������ֵ�Oldmask
        sleep(5);              //����5���ӣ�������˵��:��5s�����ڼ䣬�κ�SIGQUIT�źŶ��ᱻ�����������5s���յ��κμ��̵�quit�źţ����ʱ�����Щ��Ϣ�����ں˵Ķ����У��ȴ�5s�����󣬿���Ҫ������źš�
        
        sigpending(&pendmask); //����ź�������δ����,if (sigismember(&pendmask, SIGQUIT))//SIGQUIT������δ���ġ���ν����δ������ָSIGQUIT��������û�б�����
        {
            if (sigismember(&pendmask, SIGQUIT))
                printf("sigprocmask SIGQUIT pending\n");
        }
       
    
        /**��ʼ�����źţ������źŴ�����*/
        printf("SIGQUIT unblocked\n");
        sigprocmask(SIG_SETMASK, &oldmask, NULL); //�ָ������ε��ź�SIGQUIT
        signal(SIGQUIT, sig_quit);
        sleep(5); //�ٴ�����5����
    }

    return (0);
}