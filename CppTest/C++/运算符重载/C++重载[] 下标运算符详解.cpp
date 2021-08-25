#include <iostream>
using namespace std;

class Array
{
public:
	Array(int length = 0);
	~Array();
	
public:
	int & operator[](int i);
	const int & operator[](int i) const;
	
public:
	int length() const 
	{ 
		return m_length; 
	}
	void display() const;
	
private:
	int m_length;  //数组长度
	int *m_p;  //指向数组内存的指针
};

Array::Array(int length)
: m_length(length)
{
	if(length == 0)
	{
		m_p = NULL;
	}
	else
	{
		m_p = new int[length];
	}
}

Array::~Array()
{
	delete[] m_p;
}

int& Array::operator[](int i)
{
	return m_p[i];
}
//需要说明的是，B 是 const 对象，如果 Array 类没有提供 const 版本的operator[ ]，那么第 60 行代码将报错。虽然第 60 行代码只是读取对象的数据，并没有试图修改对象，但是它调用了非 const 版本的operator[ ]，编译器不管实际上有没有修改对象，只要是调用了非 const 的成员函数，编译器就认为会修改对象（至少有这种风险）。
const int & Array::operator[](int i) const
{
	return m_p[i];
}

void Array::display() const
{
	for(int i = 0; i < m_length; i++)
	{
		if(i == m_length - 1)
		{
			cout << m_p[i] << endl;
		}
		else
		{
			cout << m_p[i] << ", ";
		}
	}
}

int main()
{
	int n;
	cin >> n;
	Array A(n);
	for(int i = 0, len = A.length(); i < len; i++)
	{
		A[i] = i * 5;
	}
	A.display();
	
	const Array B(n);
	for(int i = 0, len = A.length(); i < len; i++)
	{
		cout<< B[i] << endl;  //访问最后一个元素
	}
	B.display();
	
	return 0;
}