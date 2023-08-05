#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream inFile;
	inFile.open("test.txt", ios::in);
	if (inFile)  //条件成立，则说明文件打开成功
		inFile.close();
	else
		cout << "test.txt doesn't exist" << endl;
		
		
	ofstream oFile;
	oFile.open("test1.txt", ios::out);
	if (!oFile)  //条件成立，则说明文件打开出错
		cout << "error 1" << endl;
	else
		oFile.close();
	oFile.open("tmp/test2.txt", ios::out | ios::in);
	
	
	if (oFile)  //条件成立，则说明文件打开成功
		oFile.close();
	else
		cout << "error 2" << endl;
		
//ios::in | ios::out	fstream	打开已存在的文件，既可读取其内容，也可向其写入数据。文件刚打开时，原有内容保持不变。如果文件不存在，则打开出错。
//		ios::in | ios::out | ios::trunc	fstream	打开文件，既可读取其内容，也可向其写入数据。如果文件本来就存在，则打开时清除原来的内容；如果文件不存在，则新建该文件。
	fstream ioFile;
	ioFile.open("test3.txt", ios::out | ios::in | ios::trunc);
	if (!ioFile)
		cout << "error 3" << endl;
	else
		ioFile.close();
		
	
	
	//使用流类的构造函数打开文件
	ifstream inFile1("test.txt", ios::in);
	if (inFile1)
		inFile1.close();
	else
		cout << "test.txt doesn't exist" << endl;
		
		
	ofstream oFile1("test1.txt", ios::out);
	if (!oFile1)
		cout << "error 1" << endl;
	else
		oFile1.close();
		
	fstream oFile2("test2.txt", ios::out | ios::in);
	if (!oFile2)
		cout << "error 2" << endl;
	else
		oFile.close();
		
		
	return 0;
}