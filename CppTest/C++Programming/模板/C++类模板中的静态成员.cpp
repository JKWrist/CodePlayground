#include <iostream>
using namespace std;

template <class T>
class A
{
private:
	static int count;
public:
	A() 
	{ 
		cout << "A() " << endl;
		count ++; 
	}
	~A() 
	{ 
		cout << "~A() " << endl;
		count -- ; 
	};
	A(A &) 
	{ 
		cout << "A(A &) " << endl;
		count ++ ; 
	}
	static void PrintCount() 
	{ 
		cout << "static void PrintCount() " << endl;
		cout << count << endl; 
	}
};

template<> int A<int>::count = 0;
template<> int A<double>::count = 0;

int main()
{
	A<int> ia;
	A<double> da;
	ia.PrintCount();
	da.PrintCount();
	return 0;
}