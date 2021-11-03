#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//  按照字符读写文件：fgetc(), fputc()
//  按照行读写文件：fputs(), fgets()
//  按照块读写文件：fread(), fwirte()
//  按照格式化读写文件：fprintf(), fscanf()
//  按照随机位置读写文件：fseek(), ftell(), rewind()

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 16:55:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按照字符读写文件 fgetc(), fputc()
void test01()
{
   //写文件
   FILE *f_write = fopen("test01.txt", "w+");

   if (f_write == NULL)
   {
      return;
   }

   char buf[] = "this is first test";

   for (int i = 0; i < strlen(buf); i++)
   {
      fputc(buf[i], f_write);
   }
   fclose(f_write);

   FILE *f_read = fopen("test01.txt", "r");
   if (f_read == NULL)
   {
      return;
   }

   char ch;
   while ((ch = fgetc(f_read)) != EOF)
   {
      printf("%c", ch);
   }

   fclose(f_read);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 16:55:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按行读写文件， fputs(), fgets()
void test02()
{
   FILE *f_write = fopen("test02.txt", "w");
   if (f_write == NULL)
   {
      return;
   }

   char *buf[] =
       {
           "锄禾日当午\n",
           "汗滴禾下土\n",
           "谁知盘中餐\n",
           "粒粒皆辛苦\n",
       };

   for (int i = 0; i < 4; i++)
   {
      fputs(buf[i], f_write);
   }
   fclose(f_write);

   FILE *f_read = fopen("test02.txt", "r");
   if (f_read == NULL)
   {
      return;
   }

   while (!feof(f_read))
   {
      char buf[1024] = {0};
      fgets(buf, 1024, f_read);
      printf("%s", buf);
   }

   fclose(f_read);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 20:42:02
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按照块读写文件 fread(), fwrite()
struct Hero
{
   char name[64];
   int age;
};

void test03()
{
   FILE *f_write = fopen("test03.txt", "w");
   if (NULL == f_write)
   {
      return;
   }

   struct Hero hero[4] =
   {
      {"可莉", 9},
      {"神华", 18},
      {"万叶", 18},
      {"班尼特", 16},
   };

   for (int i = 0; i < 4; i++)
   {
      fwrite(&(hero[i]), sizeof(struct Hero), 1, f_write);
   }
   fclose(f_write);

   FILE *f_read = fopen("test03.txt", "r");
   struct Hero tmp[4];

   fread(&tmp, sizeof(struct Hero), 4, f_read);
   for (int i = 0; i < 4; i++)
   {
      printf("姓名:%s |年龄:%d\n", tmp[i].name, tmp[i].age);
   }

   fclose(f_read);
}

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 21:12:31
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//按照格式化读写文件：fprintf(), fscanf()
void test04()
{
   //写文件
   FILE * f_write = fopen("test04.txt", "w");
   if(NULL == f_write)
   {
      return ;
   }
   fprintf(f_write, "%d-%d-%d", 2021, 10, 1);
   fclose(f_write);

   FILE * f_read  = fopen("test04.txt", "r");

   if(NULL == f_read)
   {
      return;
   }

   int array[3] = {0};
   fscanf(f_write, "%d-%d-%d", &array[0], &array[1], &array[2]);

   printf("%d-%d-%d", array[0], array[1], array[2]);
   fclose(f_read);
}
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-01 21:22:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test05()
{
   FILE * f_write = fopen("test05.txt", "w");
   if(NULL == f_write)
   {
      return;
   }

   struct Hero hero[4] =
   {
      {"可莉", 9},
      {"神华", 18},
      {"万叶", 18},
      {"班尼特", 16},
   };

   fwrite(hero, sizeof(struct Hero), 4, f_write);
   fclose(f_write);

   FILE * f_read = fopen("test05.txt", "r");
   if (NULL == f_read)
   {
      perror("文件打开失败");
      return;
   }

   struct Hero temp;
   fseek(f_read, sizeof(struct Hero) * 2, SEEK_SET);
   fread(&temp, sizeof(struct Hero), 1, f_read);
   printf("%s %d\n", temp.name, temp.age);

   fseek(f_read, -2 * sizeof(struct Hero), SEEK_CUR);
   fread(&temp, sizeof(struct Hero), 1, f_read);
   printf("%s %d\n", temp.name, temp.age);

   rewind(f_read);
   fread(&temp, sizeof(struct Hero), 1, f_read);
   printf("%s %d\n", temp.name, temp.age);

   fclose(f_read);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-01 16:55:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
   //test01();

   //test02();

   //test03();

   //test04();

   test05();

   return 0;
}
