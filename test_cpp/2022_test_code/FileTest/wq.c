#include <stdio.h>
#include <string.h>

int main()
{
    char str[1024] = {0};
    FILE *pfile = fopen("input.txt", "w");

    while (1)
    {
        memset(str, 0, sizeof(str));
        fgets(str, 4096, stdin);
        fputs(str, pfile);
        if (!strcmp(str, ":wq\n"))
        {
            break;
        }
    }
    fclose(pfile);

    return 0;
}