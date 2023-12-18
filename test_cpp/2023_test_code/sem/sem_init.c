#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define UPBOUND 100
sem_t sem1;
sem_t sem2;
void *threadfunc1(void *pvoid)
{
	int i = 0;
	while(i < UPBOUND)
	{
		sem_wait(&sem1);
		i++;
		printf("The integer of child thread1 is %d now.\n", i);
		sem_post(&sem2);
	}
}

void *threadfunc2(void *pvoid)
{
	int i = 0;
	while(i < UPBOUND)
	{
		sem_wait(&sem2);
		i++;
		printf("The integer of child thread2 is %d now.\n", i);
		sem_post(&sem1);
	}
	return (NULL);
}

int main()
{
	pthread_t tid1, tid2;

	int i = sem_init(&sem1, 0, 1);
	printf("%d\n", i);
	sem_init(&sem2, 0, 1);
	printf("Semaphores are initialized.\n");

	pthread_create(&tid1, NULL, &threadfunc1, NULL);
	pthread_create(&tid2, NULL, &threadfunc2, NULL);
	printf("Threads are started.\n");

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	printf("Threads finished.\n");

	sem_destroy(&sem1);
	sem_destroy(&sem2);
	printf("Semaphores are destoried.\n");

	printf("Main thread finished\n");
	return 0;
}