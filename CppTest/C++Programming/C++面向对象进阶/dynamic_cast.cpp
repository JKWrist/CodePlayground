#include <iostream>
#include <iomanip>
using namespace std;

class Base
{
public:
	Base(int a = 0)
	:m_a(a)
	{ 
	
	}
	
	int get_a() const
	{ 
		return m_a; 
	}
	
	virtual void func() const 
	{ 
		
	}
protected:
	int m_a;
};

class Derived: public Base
{
public:
	Derived(int a = 0, int b = 0)
	: Base(a)
	, m_b(b)
	{ 
		
	}
	
	int get_b() const 
	{ 
		return m_b; 
	}
private:
	int m_b;
};

int main()
{
	//dynamic_cast 用于在类的继承层次之间进行类型转换，它既允许向上转型（Upcasting），也允许向下转型（Downcasting）。向上转型是无条件的，不会进行任何检测，所以都能成功；向下转型的前提必须是安全的，要借助 RTTI 进行检测，所有只有一部分能成功。

//	dynamic_cast 与 static_cast 是相对的，dynamic_cast 是“动态转换”的意思，static_cast 是“静态转换”的意思。dynamic_cast 会在程序运行期间借助 RTTI 进行类型转换，这就要求基类必须包含虚函数；static_cast 在编译期间完成类型转换，能够更加及时地发现错误。
	//情况①
	Derived *pd1 = new Derived(35, 78);
	Base *pb1 = dynamic_cast<Derived*>(pd1);
	cout<<"pd1 = "<<pd1<<", pb1 = "<<pb1<<endl;
	cout<<pb1->get_a()<<endl;
	pb1->func();
	
	//情况②
	int n = 100;
	Derived *pd2 = reinterpret_cast<Derived*>(&n);
	Base *pb2 = dynamic_cast<Base*>(pd2);
	cout<<"pd2 = "<<pd2<<", pb2 = "<<pb2<<endl;
	cout<<pb2->get_a()<<endl;  //输出一个垃圾值
	pb2->func();  //内存错误
	return 0;
}