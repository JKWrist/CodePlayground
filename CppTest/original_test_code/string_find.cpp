#include <iostream>
#include <string>
using namespace std;

int main() 
{
	string s = "12+13";
	cout << s <<endl;
	// 查找
	int index = s.find("+");
	// 替换, (起始位置, 子串长度, 替换后的值，这里替换为空，相当于删除)
	string ss = s.replace(index, 1, "");
	cout << index << " " << ss <<endl;
	
	string ss1 = s.replace(index, 5, ".hl7");
	cout << index << " " << ss1 <<endl;
	// 子串
	string sub = s.substr(0, index);
	
	cout << sub <<endl;
	
		
		
	std::string s2 = "This is an example.datddddddd";
	std::cout << s2 << '\n';
	int index2 = s2.find("."); 
	s2.erase(index2, s2.length() - index2); // Erase "This "
	s2 += ".hl7";
	std::cout << s2 << '\n';
	 
//	s2.erase(std::find(s2.begin(), s2.end(), ' ')); // Erase ' '
//	std::cout << s2 << '\n';
//	 
//	s2.erase(s2.find(' ')); // Trim from ' ' to the end of the string
//	std::cout << s2 << '\n';
	return 0;
}