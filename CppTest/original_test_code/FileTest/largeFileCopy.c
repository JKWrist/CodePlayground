#include <stdio.h>
#include <string.h>
int main()
{
    char buf[1024 * 8] = {0};
    FILE *fp = fopen("a.out", "r");
    FILE *fp2 = fopen("b.out", "w");
    FILE *fp3 = fopen("c.out", "w");
    while (1)
    {
        memset(buf, 0, sizeof(buf));

        int ret = fread(buf, 1, sizeof(buf), fp);
        printf("111 %d\n", ret);

        //ret
        if (ret == 0)
        {
            break;
        }
        fwrite(buf, 1, ret, fp2);
    }

    rewind(fp);
    
    while (1)
    {
        memset(buf, 0, sizeof(buf));

        int ret = fread(buf, 1, sizeof(buf), fp);
        printf("222 %d\n", ret);

        //feof()
        if (feof(fp))
        {
            break;
        }
        fwrite(buf, 1, ret, fp3);
    }
    fclose(fp);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
