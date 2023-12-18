#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>

int main()
{
	sem_t *semaphore;
	int result;

	semaphore = sem_open("/home/xujunze/my_semaphore", O_CREAT, S_IRUSR | S_IWUSR, 1);
	if (semaphore == SEM_FAILED)
	{
		perror("sem_open");
		return 1;
	}

	result = sem_wait(semaphore);
	if (result == -1)
	{
		perror("sem_wait");
		return 1;
	}

	printf("Semaphore acquired.\n");

	sem_post(semaphore);
	printf("Semaphore released.\n");

	sem_close(semaphore);
	sem_unlink("/my_semaphore");

	return 0;
}