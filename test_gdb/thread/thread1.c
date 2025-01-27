#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *thread_func(void *thread_id)
{
    long tid = (long)thread_id;
    printf("Hello World! It's me, thread #%ld!", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    long t;
    for (t = 0; t < NUM_THREADS; t++)
    {
        printf("In main: creating thread %ld", t);
        rc = pthread_create(&threads[t], NULL, thread_func, (void *)t);
        if (rc)
        {
            printf("ERROR; return code from pthread_create() is %d", rc);
            return -1;
        }
    }
    pthread_exit(NULL);
}
