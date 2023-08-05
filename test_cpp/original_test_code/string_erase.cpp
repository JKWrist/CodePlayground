#include <iostream>
#include <algorithm>
#include <string>
 
int main()
{
	std::string s = "This is an example";
	std::cout << s << '\n';

	s.erase(0, 5); // Erase "This "
	std::cout << s << '\n';

	s.erase(std::find(s.begin(), s.end(), ' ')); // Erase ' '
	std::cout << s << '\n';

	s.erase(s.find(' ')); // Trim from ' ' to the end of the string
	std::cout << s << '\n';
	
	std::string str ="sdfklsd l;   sdff\nsdf	\ns\t\t\t\t\n  sddsf111{ sdf} f s    ";
	str.erase(std::find(str.begin(), str.end(), '\n'));
	str.erase(std::find(str.begin(), str.end(), '\t'));
	str.erase(std::find(str.begin(), str.end(), '\r'));
	str.erase(std::find(str.begin(), str.end(), ' '));
	std::cout << str << '\n';

}