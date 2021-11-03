#include <sys/stat.h>
#include <stdio.h>
int main()
{
    struct stat buf;
    stat("a.out", &buf);  //传出参数

    printf("stat filesieze %d\n", buf.st_size);


    FILE *fp = fopen("a.out", "r+");
    if(fp == NULL)
        perror("fopen");

    fseek(fp, 0, SEEK_END);
    long ret = ftell(fp);
    printf("ftell filesieze %ld\n", ret);

    fclose(fp);
    return 0;
}
