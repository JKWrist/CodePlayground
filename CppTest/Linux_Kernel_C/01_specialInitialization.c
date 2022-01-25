#include <stdio.h>

struct student{
  char name [20];
  int age;
};

void test01()
{
  struct student st1 = {"xiaobai", 20};

  struct student st2 =
  {
    .name = "xiaohong",
    .age = 2,
  };

  printf("%s %d %s %d\n", st1.name, st1.age, st2.name, st2.age);
}

void test02()
{
  int i = 4;
  switch(i)
  {
    case 1:
      printf("1\n");
      break;
    case 2 ... 8:
      printf("2-8\n");
      break;
    case 9:
      printf("9\n");
      break;
    case 10:
      printf("10\n");
      break;
  }
}

void test03()
{
  int array1[1000] = {[1] = 2, [10] = 100, [200] = 1};

  for(int i = 0; i < 1000; i++)
  {
    printf("%d ", array1[i]);
    if(i % 100 == 0)
    {
      printf("\n");
    }
  }
}

int main()
{
  
  //test01();

  //test02();

  test03();
  return 0;
}
