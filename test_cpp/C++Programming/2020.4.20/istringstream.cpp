#include <iostream>
#include <sstream>
using namespace std;
using std::stringstream;

// 本地
// 标准I/O istream/ostream
// 文件I/O ifstream/ofstream/fstream
// 字符串I/O istringstream/ostringstream/stringstream

// 网络I/O Socket
void test0()
{
	//snprintf
	int n1 = 100, n2 = 200;
	stringstream ss;
	ss << "n1 = " << n1 << " n2 = " << n2 << endl;
	
	string line = ss.str();
	cout << line << endl;
	
	string word;
	int number;
	while(ss >> word >> number, !ss.eof())
	{
		cout << word << " " << number << "\n";
	}
	cout << endl;
}

string int2str(int number)
{
	ofstream oss;
	oss << number;
	return oss.str();
}

int main(int argc, char *argv[]) 
{
	test0();
	int2str(4);
	return 0;
}