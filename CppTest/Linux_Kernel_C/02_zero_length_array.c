#include <stdio.h>

void test01()
{
  int len;
  int a[len];
}

void test02()
{
  int buffer[0];
  printf("%lu\n", sizeof(buffer));
}

void test03()
{
  struct stu
  {
    int len;
    char buffer[0];
  };

  printf("%lu\n", sizeof(struct stu));

}

int main()
{
  test01();
  test02();
  
  test03();
}


