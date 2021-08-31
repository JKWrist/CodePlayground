#include <stdio.h>
#include <string.h>

/* The input mac format could be like aa:bb:cc:dd:ee:ff, aa-bb-cc-dd-ee-ff or aabbccddeeff */
static void mac_del_colon(char *dest, char *src)
{
    if (src == NULL || dest == NULL)
    {
        printf("Get NULL pointer of mac!\n");
        return;
    }

    int i = 0, j = 0, len = strlen(src);
    while (i < len)
    {
        if (src[i] == ':' || src[i] == '-')
        {
            i++;
        }
        else
        {
            dest[j++] = src[i++];
        }
    }
    dest[j] = '\0';
}

//a to A
static void str_toupper(char *dest, char *src)
{
    if (src == NULL || dest == NULL)
    {
        printf("Get NULL pointer of mac!\n");
        return;
    }
    int i = 0, j = 0, len = strlen(src);
    //原有崩溃的地方strlen(strlen(src))注意细节问题;
    for (i; i < len; i++)
    {
        if (src[i] >= 'a' && src[i] <= 'f')
        {
            dest[j++] = src[i++] - 32;
        }
        else
        {
            dest[j++] = src[i++];
        }
    }
    dest[j] = '\0';
}

//A to a
static void str_tolower(char *dest, char *src)
{
    if (src == NULL || dest == NULL)
    {
        printf("Get NULL pointer of mac!\n");
        return;
    }
    
    int i = 0, j = 0, len = strlen(src);
    for (i; i < strlen(src); i++)
    {
        if (src[i] >= 'A' && src[i] <= 'F')
        {
            dest[j++] = src[i++] + 32;
        }
        else
        {
            dest[j++] = src[i++];
        }
    }
    dest[j] = '\0';
}

int main()
{
    const char src[18] = "00:E0:4C:36:33:C2";
    char delete_delim_mac[20] = {0}, delete_delim_vmac[20] = {0};
    char tmp_mac[20] = {0};
    mac_del_colon(tmp_mac, src);
    str_toupper(delete_delim_mac, tmp_mac);

    return 0;
}