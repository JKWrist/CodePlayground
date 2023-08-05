#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANDOM_FILE "random.txt"

int iRandom[12] = {0};
int iGetFileRandom[12] = {0};

//bigger at right
void bubble_sort()
{
    int len = sizeof(iGetFileRandom) / sizeof(iGetFileRandom[0]);
    int tmp = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (iGetFileRandom[j] > iGetFileRandom[j+1])
            {
                tmp = iGetFileRandom[j];
                iGetFileRandom[j] = iGetFileRandom[j+1];
                iGetFileRandom[j+1] = tmp;
            }
        }
    }
}

void random_get()
{
    srand(time(NULL));
    for (int i = 0; i < 12; i++)
    {
        iRandom[i] = rand() % 100;
        //printf("%d %d\n", i, iRandom[i]);
    }
}

void write_random_to_file(int * pInt)
{
    FILE *fp = fopen(RANDOM_FILE, "w");
    if (fp == NULL)
    {
        printf("fopen error\n");
    }

    for (int i = 0; i < 12; i++)
    {
        fprintf(fp, "%d\n", pInt[i]);
        //printf("%d %d\n", i, pInt[i]);
    }
   
    fclose(fp);
}

void read_random_to_str()
{
    FILE *fp = fopen(RANDOM_FILE, "r");
    if(fp == NULL)
    {
        printf("fopen error\n");
    }
    int i = 0;
    while(1)
    {
        fscanf(fp, "%d\n", &iGetFileRandom[i]);
        //printf("%d %d\n", i, iGetFileRandom[i]);
        i++;
        if(feof(fp))
        {
            break;
        }
    }
    fclose(fp);
}

int main()
{
    random_get();
    write_random_to_file(iRandom);
    read_random_to_str();

    getchar();

    //sort
    bubble_sort();
    write_random_to_file(iGetFileRandom);
    return 0;
}