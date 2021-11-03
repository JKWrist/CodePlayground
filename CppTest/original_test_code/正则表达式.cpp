#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(int argc, char *argv[]) 
{
	std::string str ="sdfklsd l;   sdff\nsdf    	\ns\t\t\t\t\n  sddsf111{ sdf} f s    ";

	regex pattern(" |\n|\r|\t");
	std::string fmt = "";
	std::string ret = std::regex_replace(str, pattern, fmt);
	std::cout << ret << std::endl;
	
	
	string res = "sdfklsd l;  \n";
	//删除换行符
	int r = res.find('\n');
	while (r != string::npos)
	{
		if (r != string::npos)
		{
			res.replace(r, 1, "");
			r = res.find('\n');
		}
	}

	//删除所有空格
	res.erase(std::remove_if(res.begin(), res.end(), std::isspace), res.end());
}