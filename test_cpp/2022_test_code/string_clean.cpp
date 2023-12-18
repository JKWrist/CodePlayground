#include<iostream>
#include<string>
using namespace std;

int main(){
	string str = "hello c++! +++";
	// 从位置pos=10处开始删除，直到结尾
	// 即： " +++"
	str.erase(10);
	cout << '-' << str << '-' << endl;
	// 从位置pos=6处开始，删除4个字符
	// 即: "c++!"
	str.erase(6, 4);
	cout << '-' << str << '-' << endl;
	
	str = "";
	//str.clear();//清空该字符串
	cout << str << endl;//str空了,所以只输出了endl
	
	str = "sasd";
	cout << str << endl;

	return 0;
}