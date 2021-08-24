#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
//	int sum = 0, value = 0;
//	while(cin >> value)
//	sum += value;
//	
//	cout << "Sum is :" << sum << endl;
	
//	string line;
//	while(getline(cin, line))
//		cout << line << endl;
	
//	string str("some string");
//	for(auto c : str)
//	cout << c << endl;
	
//	string str("some string");
//	for(auto &c : str)
//		c = toupper(c);
//	cout << str << endl;
	
//	string s("some string");
//	for(decltype(s.size()) index = 0; 
//				index != s.size() && !isspace(s[index]); index++)		
//	{
//		s[index] = toupper(s[index]);
//	}
	string s = "abcdefg";
	s += 'a';
	cout << s << endl;
	return 0;
}