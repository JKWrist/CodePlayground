#include <stdio.h>

int main()
{
    char buffer[50];
    char* s = "runoobcom";
// 读取字符串并存储在 buffer 中
    int j = snprintf(buffer, 6, "%s\n", s);

// 输出 buffer及字符数
    printf("string:\n%s\ncharacter count = %d\n", buffer, j);
  return 0;
}
