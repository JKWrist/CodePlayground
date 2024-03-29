#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	int *p1[6];  //指针数组 6个指针元素
	int *(p2[6]);  //指针数组，和上面的形式等价
	int (*p3)[6];  //二维数组指针
	int (*p4)(int, int);  //函数指针
	//我相信大部分初学者对上面几种形式的指针都非常迷惑，不知道该从哪里入手去理解，为什么 p1、p2 是数组，而 p3 却是指针呢，它们仅仅是一个括号的区别。
	
	char *(* c[10])(int **p);
	int (*(*(*pfunc)(int *))[5])(int *);
	
//	C语言标准规定，对于一个符号的定义，编译器总是从它的名字开始读取，然后按照优先级顺序依次解析。对，从名字开始，不是从开头也不是从末尾，这是理解复杂指针的关键！
//
//	对于初学者，有几种运算符的优先级非常容易混淆，它们的优先级从高到低依次是：
	//高
//	3、定义中被括号( )括起来的那部分。
//	2、后缀操作符：括号( )表示这是一个函数，方括号[ ]表示这是一个数组。
//	1、前缀操作符：星号*表示“指向xxx的指针”。
	//低
//	学会了“绝杀招式”，接下来我们就由浅入深，逐个击破上面的指针定义。
	
	/
	1) int *p1[6];
	从 p1 开始理解，它的左边是 *，右边是 [ ]，[ ] 的优先级高于 *，所以编译器先解析p1[6]，p1 首先是一个拥有 6 个元素的数组，然后再解析int *，它用来说明数组元素的类型。从整体上讲，p1 是一个拥有 6 个 int * 元素的数组，也即指针数组。
	
	
	
	2) int (*p3)[6];
	从 p3 开始理解，( ) 的优先级最高，编译器先解析(*p3)，p3 首先是一个指针，剩下的int [6]是 p3 指向的数据的类型，它是一个拥有 6 个元素的一维数组。从整体上讲，p3 是一个指向拥有 6 个 int 元素数组的指针，也即二维数组指针。
	为了能够通过指针来遍历数组元素，在定义数组指针时需要进行降维处理，例如三维数组指针实际指向的数据类型是二维数组，二维数组指针实际指向的数据类型是一维数组，一维数组指针实际指向的是一个基本类型；在表达式中，数组名也会进行同样的转换（下降一维）。
	
	
	
	3) int (*p4)(int, int);
	从 p4 开始理解，( ) 的优先级最高，编译器先解析(*p4)，p4 首先是一个指针，它后边的 ( ) 说明 p4 指向的是一个函数，括号中的int, int是参数列表，开头的int用来说明函数的返回值类型。整体来看，p4 是一个指向原型为int func(int, int);的函数的指针。
	
	
	
	4) char *(* c[10])(int **p);
	这个定义有两个名字，分别是 c 和 p，乍看起来 p 是指针变量的名字，不过很遗憾这是错误的。如果 p 是指针变量名，c[10]这种写法就又定义了一个新的名字，这让人匪夷所思。

	以 c 作为变量的名字，先来看括号内部（绿色粗体）：
	char * (* c[10]) (int **p);

	[ ] 的优先级高于 *，编译器先解析c[10]，c 首先是一个数组，它前面的*表明每个数组元素都是一个指针，只是还不知道指向什么类型的数据。整体上来看，(* c[10])说明 c 是一个指针数组，只是指针指向的数据类型尚未确定。

	跳出括号，根据优先级规则（() 的优先级高于 *）应该先看右边（红色粗体）：
	char * (* c[10]) (int **p);

	( )说明是一个函数，int **p是函数参数。

	再看左边（橘黄色粗体）：
	char * (* c[10]) (int **p);

	char *是函数的返回值类型。

	从整体上看，我们可以将定义分成两部分：
	char * (* c[10]) (int **p);

	绿色粗体表明 c 是一个指针数组，红色粗体表明指针指向的数据类型，合起来就是：c 是一个拥有 10 个元素的指针数组，每个指针指向一个原型为char *func(int **p);的函数。
	
	
	
	5) int (*(*(*pfunc)(int *))[5])(int *);
	从 pfunc 开始理解，先看括号内部（绿色粗体）：
	int (*(*(*pfunc)(int *))[5])(int *);

	pfunc 是一个指针。

	跳出括号，看它的两边（红色粗体）：
	int (*(*(*pfunc)(int *))[5])(int *);

	根据优先级规则应该先看右边的(int *)，它表明这是一个函数，int *是参数列表。再看左边的*，它表明函数的返回值是一个指针，只是指针指向的数据类型尚未确定。

	将上面的两部分合成一个整体，如下面的蓝色粗体所示，它表明 pfunc 是一个指向函数的指针，现在函数的参数列表确定了，也知道返回值是一个指针了（只是不知道它指向什么类型的数据）。
	int (* (*(*pfunc)(int *)) [5])(int *);

	蓝色粗体以外的部分，就用来说明函数返回什么类型的指针。

	我们接着分析，再向外跳一层括号（红色粗体）：
	int (* (*(*pfunc)(int *)) [5])(int *);

	[ ] 的优先级高于 *，先看右边，[5] 表示这是一个数组，再看左边，* 表示数组的每个元素都是指针。也就是说，* [5] 是一个指针数组，函数返回的指针就指向这样一个数组。

	那么，指针数组中的指针又指向什么类型的数据呢？再向外跳一层括号（橘黄色粗体）：
	int (* (*(*pfunc)(int *)) [5]) (int *);

	先看橘黄色部分的右边，它是一个函数，再看左边，它是函数的返回值类型。也就是说，指针数组中的指针指向原型为int func(int *);的函数。

	将上面的三部分合起来就是：pfunc 是一个函数指针（蓝色部分），该函数的返回值是一个指针，它指向一个指针数组（红色部分），指针数组中的指针指向原型为int func(int *);的函数（橘黄色部分）。
	*/
}