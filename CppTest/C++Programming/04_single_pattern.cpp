//单例模式

#include <iostream>
using namespace std;

//主席类
class ChairMan
{
public:
	static ChairMan * getInstance()
	{
		return singleMan;
	}
private:
	//将构造函数私有化，不可以创建多个对象
	ChairMan(){};

	ChairMan(const ChairMan & p){}
private:
	//将主席指针私有化，对外提供只读接口
	static ChairMan * singleMan;
};

ChairMan * ChairMan::singleMan = new ChairMan;

void test01()
{
	// ChairMan c1;
	// ChairMan c2;
	// ChairMan * c3 = new ChairMan;

	ChairMan * c1 = ChairMan::getInstance();
	ChairMan * c2 = ChairMan::getInstance();
	//ChairMan c3 = *c2;
	//要将拷贝构造函数也设置为私有成员函数，防止拷贝构造的发生

	if(c1 == c2)
	{
		cout << "c1 == c2" << endl;
	}
	else
	{
		cout << "c1 != c2" << endl;
	}
	cout << c1 << endl;
	cout << c2 << endl;
	// cout << &c3 << endl;
}

int main()
{
	test01();

	return 0;
}