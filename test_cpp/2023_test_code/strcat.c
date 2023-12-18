#include <stdio.h>
#include <string.h>

int main() {
    char hostname[100] = "hostname:";
    char source[] = "T36 Max";

    strcat(hostname, source);

    printf("拷贝后的字符串: %s\n", hostname);

	char str[20] = "123";
char  *src = "hello world";
printf("%s\n", strncat(str, src, strlen(src)));

    return 0;
}