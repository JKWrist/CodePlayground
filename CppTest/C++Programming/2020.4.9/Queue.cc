#include <iostream>
using namespace std;
class Queue
{
public:
	Queue(int size = 10)
	: _size(size)
	, _array(new int[_size]())
	, _head(0)
	, _tail(0)
	{}
	
	~Queue()
	{
		delete[] _array;
	}
	
	bool empty() const
	{
		return _head == _tail;
	}
	
	bool full() const
	{
		return _head == (_tail + 1) % _size;
	}
	
	void push(int number)
	{
		if(!full())
		{
			_array[_tail++] = number;
			_tail %= _size;
		}
		else
		{
			cout << "队列满" << endl;
		}
	}
	
	void pop()
	{
		if(!empty())
		{
			_head++;
			_head %= _size;
		}
	}
	
	int front()
	{
		return _array[_head];
	}
	
	int back()
	{
		return _array[(_tail - 1 + _size) % _size];	
	}
private:
	int _size;
	int * _array;
	int _head;
	int _tail;		
};


int main(int argc, char *argv[]) 
{
	Queue que;
	cout << "此时队列是否为空:" << que.empty() << endl;
	
	que.push(1);
	cout << "此时队列是否为空:" << que.empty() << endl;
	
	for(int idx = 2; idx != 12; idx++)
		que.push(idx);
	cout << "此时队列是否为空:" << que.empty() << endl;
	
	while(!que.empty())
	{
		cout << que.front() << " ";
		que.pop();
	}
	cout << endl;
	
	cout << "此时队列是否为空:" << que.empty() << endl;
	return 0;
}