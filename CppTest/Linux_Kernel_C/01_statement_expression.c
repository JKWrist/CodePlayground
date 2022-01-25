#include <stdio.h>

void test01()
{ 
  int sum;
  sum = 
  ({
    int s;
    for(int i = 0; i < 10; i++)
      s = s + i;
    s;
  });

  printf("%d\n", sum);
}

int main()
{
  test01();

}
