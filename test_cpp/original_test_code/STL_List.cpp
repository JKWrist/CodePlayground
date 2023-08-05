#include <iostream>
#include <list>
using namespace std;
int main(int argc, char *argv[]) 
{
	list<int> pList;
	cout << "push_back() , pop_back() ，begin() ,  end()测试：" << endl;
	pList.push_back(1); //尾插
	pList.push_back(2);
	pList.push_back(3);
	pList.push_back(4);
	pList.push_back(5);
	cout <<*( pList.begin() ) << endl;
	cout << (pList.back()) << endl; // end()返回最后一个元素后面的迭代器
	pList.pop_back();  //尾删
	cout << *(pList.begin()) << endl;
	cout << (pList.back()) << endl;
	pList.pop_front();  //头删
	cout << *(pList.begin()) << endl;
	cout << (pList.back()) << endl;
	
	cout << "rbegin() , rend() 测试 : " << endl;
	cout <<*( pList.rbegin() )<<endl;  //rbegin()返回end()-1的位置
														  //rend() 返回begin()-1的位置
 
	cout << "front() , back() 测试 : " << endl;  //返回的是引用
	cout << pList.front() << "~~~" << pList.back() << endl;
 
	cout << "push_front() , pop_front()   测试 : " << endl;  //前插，前删  
	
	cout << *(pList.begin()) << endl;
	pList.push_front(11);
	cout << *(pList.begin()) << endl;
 
	pList.pop_front();
	cout << *(pList.begin()) << endl;
 
	cout << "   insert() , erase() , iterator  ,empty() 测试 : " << endl;
	
	list<int>::iterator it = pList.begin();
 
		pList.insert(it, 8);
 
	for (it = pList.begin(); it != pList.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;
 
	for (it = pList.begin(); it != pList.end(); )  //查看是否迭代器会失效
	{
		it = pList.erase(it );  //必须接受erase的返回值，否则出错咯
	}
	cout << pList.empty() << endl;
 
 
	pList.push_back(5);
	pList.push_back(3);
	pList.push_back(1);
	pList.push_back(7);
	pList.push_back(3);
	cout << "sort() , unique()  , remove() , splice()"<< endl;
 
	pList.sort();  //排序
	for (it = pList.begin(); it != pList.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;
 
	pList.unique();  //去重!
	for (it = pList.begin(); it != pList.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;
 
	pList.remove(7);  //移除具体的内容
 
	for (it = pList.begin(); it != pList.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;
	it = pList.begin();
	//pList.splice  //现list拼接的功能。将源list的内容部分或全部元素删除，拼插入到目的list
	list<int> list1;
	list1.push_back(0);
	list1.push_back(2);
	list1.push_back(4);
	pList.splice(it, list1);
	for (it = pList.begin(); it != pList.end(); ++it)
	{
		cout << *it << "    ";
	}
	cout << endl;
	cout<< list1.empty() << endl;
}