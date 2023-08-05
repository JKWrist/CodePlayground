#include <iostream>
#include <string>
using namespace std;

class Base{ };
class Derived: public Base{ };

int main(){
	try
	{
		throw Derived();  //抛出自己的异常类型，实际上是创建一个Derived类型的匿名对象
		cout<<"This statement will not be executed."<<endl;
	}
	catch(int)
	{
		cout<<"Exception type: int"<<endl;
	}
	catch(char *)
	{
		cout<<"Exception type: cahr *"<<endl;
	}
	catch(Base)
	{  
		//匹配成功（向上转型）
		cout<<"Exception type: Base"<<endl;
	}
	catch(Derived)
	{
		cout<<"Exception type: Derived"<<endl;
	}
	return 0;
}