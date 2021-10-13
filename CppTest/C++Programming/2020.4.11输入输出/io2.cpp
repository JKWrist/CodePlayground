#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void test1()
{
	//文件输入流要求所读文件必须存在
	ifstream ifs("test.txt");
	if(!ifs.good())
	{
		cout << "ifstream create error" << endl;
		return;
	}
	string word;
	string line;
	
	vector<string> lines;
	lines.reserve(20);
	//string lines[100];//问题是不能确定行数大小
	int idx = 0;
//	while(ifs >> word) //同cin一样只不过是文件流， 输入流自动用空格换行符分割
//		cout << word << endl;
	
	while(std::getline(ifs, line))
	{
		//lines[idx++] = line; //Terminated due to signal: SEGMENTATION FAULT (11)
		//此处只能用push_back操作
		lines.push_back(line);
		//cout << line << endl;
	}
	
	for(idx = 0; idx != 5; idx++)
	{
		cout << lines[idx] << endl;
	}
	
	for(auto &elem : lines)
	{
		cout << elem << endl;
	}
	ifs.close();
}
int main(int argc, char *argv[]) 
{
	test1();
	return 0;
}