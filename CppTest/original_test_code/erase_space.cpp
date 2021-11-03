#include <iostream>
#include <string>
using namespace std;

//去掉收尾空格
string& ClearHeadTailSpace(string &str)   
{  
	if (str.empty())   
	{  
		return str;  
	}  
	str.erase(0,str.find_first_not_of(" "));  
	str.erase(str.find_last_not_of(" ") + 1);  
	return str;  
}  

//去掉字符串中的全部空格
string& ClearAllSpace(string &str)
{
    int index = 0;
    if( !str.empty())
    {
        while( (index = str.find(' ',index)) != string::npos)
        {
            str.erase(index,1);
        }
    }
	return str;
}

int main()
{
	string str = "   123   456   789   ";
	cout << ClearHeadTailSpace(str) << endl;
	cout << ClearAllSpace(str) << endl;
	return 0;
}