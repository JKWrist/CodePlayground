
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *fp;
    char buf[512];
    char *pError;
    int bExec = 0;

    fp = popen("ifconfig", "r");
    if (NULL == fp)
    {
        printf("ifconfig error\n");
        return 0;
    }

    while (fgets (buf, sizeof(buf), fp) != NULL)
    {
        if ((pError = strstr(buf, "lo")) != NULL)
        {
            bExec = 1;
            break;
        }
        else
        {
            printf("exec2 %p\n", pError);
        }
    }

    if (bExec)
    {
        printf("found\n");
    }
    pclose(fp);
    return 0;
}