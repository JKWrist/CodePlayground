#include <iostream>
#include <vector>
using namespace std;

void printfNumbers(vector<int> & vec)
{
	cout << vec.size() << endl
		 << vec.capacity() << endl << endl;
}


//动态数组实现策略
//1.当size() == capasity()时， 直接开辟2 * size()的空间
//2.将原来空间的元素复制到新空间上
//3.销毁原来空间元素， 释放原来空间
//4.在新空间添加元素

int main(int argc, char *argv[]) 
{
	vector<int> numbers;
	//numbers.reserve(20); //避免频繁扩容操作，效率比较低
	
	numbers.push_back(1);
	printfNumbers(numbers);
	
	numbers.push_back(2);
	printfNumbers(numbers);
	
	numbers.push_back(3);
	printfNumbers(numbers);
	
	numbers.push_back(4);
	printfNumbers(numbers);
	
	numbers.push_back(5);
	printfNumbers(numbers);
	
	for(size_t idx =0; idx != numbers.size(); idx++)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	
	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	return 0;
}