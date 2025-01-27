#include <stdio.h>
#include <pthread.h>

void *printNumbers(void *arg)
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("Thread: %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, printNumbers, NULL);
    pthread_create(&thread2, NULL, printNumbers, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
