#include <stdio.h>

int main()
{
   for(int i = 0; i < 9; i++)
   {
      char arr[64];
      //在这里只会新建一个数组，而不是for循环中的数量
      printf("%x\n", arr);
   }
}
