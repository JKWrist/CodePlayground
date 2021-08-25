
//在大多数情况下数组名确实可以当做指针使用
#include <stdio.h>
int main()
{
	int a[6] = {0, 1, 2, 3, 4, 5};
	int *p = a;
	int len_a = sizeof(a) / sizeof(int);
	int len_p = sizeof(p) / sizeof(int);
	printf("sizeof(a) = %d, sizeof(int) = %d\n", sizeof(a), sizeof(int));
	printf("sizeof(p) = %d, sizeof(int) = %d\n", sizeof(p), sizeof(int));
	printf("len_a = %d, len_p = %d\n", len_a, len_p);
	return 0;
}

//站在编译器的角度讲，变量名、数组名都是一种符号，它们最终都要和数据绑定起来。变量名用来指代一份数据，数组名用来指代一组数据（数据集合），它们都是有类型的，以便推断出所指代的数据的长度。
//
//数组也有类型，这是很多读者没有意识到的，大部分C语言书籍对这一点也含糊其辞！我们可以将 int、float、char 等理解为基本类型，将数组理解为由基本类型派生得到的稍微复杂一些的类型。sizeof 就是根据符号的类型来计算长度的。
//
//对于数组 a，它的类型是int [6]，表示这是一个拥有 6 个 int 数据的集合，1 个 int 的长度为 4，6 个 int 的长度为 4×6 = 24，sizeof 很容易求得。