#include <iostream>
#include <stdlib.h>
using namespace std;
 
//任务的实现者
class idea
{
public:
	void GreatIdea1()
	{
		cout << "第一个锦囊：\n\t一到江东就拜会乔国佬" << endl;
	}
	 
	void GreatIdea2()
	{
		cout << "第一个锦囊：\n\t刘备被孙权设计留下就对他谎称曹操大军压境" << endl;
	}
	 
	void GreatIdea3()
	{
		cout << "第一个锦囊：\n\t被东吴军队追赶就求孙夫人解围" << endl;
	}
};
 
//定义函数指针类型,确定一个函数指针，无函数参数，返回值为void
//typedef void(*MyIdea)();
//
////任务的调用者
//void MainOp(MyIdea my)
//{
//	my();
//}
 
void MainOp(void(*MyIdea)())
{
	MyIdea();
}
 
int main()
{
	idea a;
	MainOp(idea::GreatIdea1);
	MainOp(idea::GreatIdea2);
	MainOp(idea::GreatIdea3);
}