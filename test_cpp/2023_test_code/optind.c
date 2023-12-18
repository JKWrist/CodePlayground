#include <unistd.h>
#include <stdio.h>

//   ./a.out file1 -a -b -c code -d file2 -e file3

//   ./a.out file1 -a -b -c code -d file2 -efile3
//    ab:c:de::

int main(int argc, char *argv[])
{
	int aflag = 0, bflag = 0, cflag = 0;
	int ch;
	printf("--------------------------\n");
	for (int i = 0; i < argc; i++)
	{
		printf("%d %s\n", i, argv[i]);
	}
	printf("--------------------------\n");
	printf("optind:%d, opterr:%d\n", optind, opterr);
	printf("--------------------------\n");

/*
	extern char *optarg;
	//选项的参数指针

	extern int  optind
	//下一次调用getopt的时，从optind存储的位置处重新开始检查选项。 

	extern int  opterr
	//当opterr=0时，getopt不向stderr输出错误信息。

	extern int  optopt;
	// 当命令行选项字符不包括在 optstring中或者选项缺少必要的参数时，
	// 该选项存储在optopt 中，getopt返回'？’

	int getopt(int argc，char * const argv[]，const char *optstring);
	// 调用一次，返回一个选项。
	// 在命令行选项参数再也检查不到optstring中包含的选项时，返回－1，
	// 同时optind储存第一个不包含选项的命令行参数。

1.单个字符，表示选项，
2.单个字符后接一个冒号：表示该选项后必须跟一个参数。参数紧跟在选项后或者以空格隔开。该参数的指针赋给optarg。
3.单个字符后跟两个冒号，表示该选项后必须跟一个参数。参数必须紧跟在选项后不能以空格隔开。该
参数的指针赋给optarg。（这个特性是GNU的扩展）。
*/
	while ((ch = getopt(argc, argv, "ab:c:de::")) != -1)
	{
		printf("optind: %d,argc:%d,argv[%d]:%s\n", optind, argc, optind, argv[optind]);
		switch (ch)
		{
		case 'a':
			printf("HAVE option: -a\n");
			printf("--------------------------\n");
			break;
		case 'b':
			printf("HAVE option: -b\n");

			printf("The argument of -b is %s\n", optarg);
			printf("--------------------------\n");
			break;
		case 'c':
			printf("HAVE option: -c\n");
			printf("The argument of -c is %s\n", optarg);
			printf("--------------------------\n");
			break;
		case 'd':
			printf("HAVE option: -d\n");
			printf("--------------------------\n");
			break;
		case 'e':
			printf("HAVE option: -e\n");
			printf("The argument of -e is %s\n", optarg);
			printf("--------------------------\n");
			break;

		case '?':
			printf("Unknown option: %c\n", (char)optopt);
			printf("--------------------------\n");
			break;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d %s\n", i, argv[i]);
	}
	printf("--------------------------\n");
}