#include <iostream>

using namespace std;
int main(int argc, char *argv[]) 
{
	cout << "\'/\'错误，应该为\'\\',请重新输入！" << endl;
	cout << "错误，应该为请重新输入！" << endl;
	cout << "\'/\'  \'\\'" << endl;
	
	string ans="example:";
	char c1 ='0'+1;
	char c2 ='0'+2;
	char c3 ='0'+3;
	char c4 ='0'+4;
	char c5 ='0'+5;
	char *p = "asdasdas";
	ans += c1 + c2 + c3 + c4 + c5;
	cout << ans << endl;	
	

	ans += c1 + c2;
	cout << ans << endl;
	
	ans += c1;
	ans += c2;
	ans += c3;
	ans += c4;
	ans += c5;
	cout << ans << endl;
	
	ans += p;
	cout << ans << endl;
	
	cout << "I love world \n";
	cout << "I love world \n";
	cout << "I love world \n";
	cout << "I love world \n";
	
	string str1 = "asd";
	string str2 = "asd";
	if(str1 == str2)
	{
		cout << "ok" << endl;
	}
}