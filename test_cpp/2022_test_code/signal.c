#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <unistd.h>

#define THREAD_NUM 10
pthread_t tid[10];
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void sig_handler(int sig)
{
    pthread_mutex_lock(&mutex);
    printf("sig_handler\n");
    pthread_mutex_unlock(&mutex);
}

void *thread_handler(void *arg)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        printf("thread_handler %ld\n", pthread_self());
        usleep(1000);
        pthread_mutex_unlock(&mutex);
    }
}
void *t_handler(void *arg)
{
    while (1)
    {
        printf("t_handler %ld\n", pthread_self());
        usleep(1000);
    }
}
int main()
{
    signal(SIGINT, sig_handler);
    int i;
    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_create(&tid[i], NULL, thread_handler, NULL);
    }
    pthread_t t;
    pthread_create(&t, NULL, t_handler, NULL);

    for (i = 0; i < THREAD_NUM; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}