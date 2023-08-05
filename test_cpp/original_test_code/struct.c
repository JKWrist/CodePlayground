#include <stdio.h>
#include <signal.h>
struct student
{
    char name[32];
    char sex;
    int age;
} CollageStu;

int main()
{
    
    printf("%d , %d, %d\n", SIGUSR1, 1 << SIGUSR1, (0 & (1 << SIGUSR1)));

    printf("%d , %d\n", SIGUSR2, (~(1 << SIGUSR1)) );
}