#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>

static char g_str_private_key[4096] = {0};
static char g_str_public_key[4096] = {0};

//读取公钥和私钥数据
int main()
{
    struct stat st = {0};
    int ret = stat("./priy.pem", &st);
    if(-1 == ret)
    {
        printf("error\n");
    }

    char tmp[1024] = {0};
    FILE *private = fopen("./prikey.pem", "r+");
    fseek(private,31, SEEK_CUR);
    while (!feof(private))
    {
        memset(tmp, 0, sizeof(tmp));
        fscanf(private, "%s\n", tmp);
        if (tmp[0] != '-')
        {
            strcat(g_str_private_key, tmp);
        }
        else
        {
            break;
        }
    }
    printf("g_str_private_key\n%s \n", g_str_private_key);
    fclose(private);

    // for (int i = 0; i <= 80; i++)
    // {
    //     printf("%c %d\n", g_str_private_key[i], g_str_private_key[i]);
    // }

    FILE *public = fopen("./pubkey.pem", "r+");
    fseek(public, 26, SEEK_CUR);
    printf("g_str_public_key\n%s \n", g_str_public_key);
    while (!feof(public))
    {
        memset(tmp, 0, sizeof(tmp));
        fscanf(public, "%s\n", tmp);
        if (tmp[0] != '-')
        {
            strcat(g_str_public_key, tmp);
        }
        else
        {
            break;
        }
    }
    printf("g_str_public_key\n%s \n", g_str_public_key);
    fclose(public);
}