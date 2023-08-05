#include <stdio.h>
#include <sys/time.h>

struct student
{
    char name[256];
    int age;
};

int caltime(struct timeval *tv1, struct timeval*tv2)
{
    return (tv2->tv_sec - tv1->tv_sec) * 1000000 + (tv2->tv_usec - tv1->tv_usec);
}

int main(int argc, char *argv[])
{
    struct student st1 = {"xixaobai", 25};

    int ret = st1.age;

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);
    for (int i = 0; i < 800000; i++)
    {
        int t1 = st1.age;
    }
    
    gettimeofday(&tv2, NULL);
    printf("1111 %d\n", caltime(&tv1, &tv2));

    gettimeofday(&tv1, NULL);
    for (int i = 0; i < 800000; i++)
    {
        int t1 = ret;
    }
    gettimeofday(&tv2, NULL);
    printf("2222 %d\n", caltime(&tv1, &tv2));
}