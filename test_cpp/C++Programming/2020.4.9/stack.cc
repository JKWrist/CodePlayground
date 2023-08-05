#include <iostream>
using namespace std;

class Stack
{
public:
	Stack(int size = 10)
	: _size(size)
	, _top(-1)
	, _array(new int[_size]())
	{
		
	}
	
	~Stack()
	{
		delete [] _array;
	}
	bool empty() const
	{
		return _top == -1;
	}
	bool full() const
	{
		return _top == _size - 1;
	}
	void push(int value)
	{
		if(!full())
		{
			_array[++_top] = value;
		}
		else 
		{
			cout << "栈满了" <<endl;
		}
	}
	
	void pop()
	{
		if(!empty())
		{
			_top--;
		}
		else 
		{
			cout << "栈空" << endl;	
		}
	}
	
	int top()
	{
		if(!empty())
		{
			return _array[_top];
		}
		else
		{
			cout << "栈空" << endl;
			return 0;
		}
	}

private:
	int _size;
	int _top;
	int * _array;	
};

int main(int argc, char *argv[]) 
{
	Stack stack;
	cout << "此时栈是否为空" << endl
		 << stack.empty() << endl;
	
	stack.push(19);
	cout << "此时栈是否为空" << endl
			 << stack.empty() << endl;
			
	cout << stack.top() << endl;
	return 0;
}