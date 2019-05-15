#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
	string s;
	while(getline(cin, s))
	{
		int n = 0, flag = 1;
		for (int i = s.length()-1; i >= 0; --i)
		{
			if(flag && s[i] == ' ')
				continue;
			else if(s[i] != ' ')
			{
				flag = 0;
				++n;
			}
			else {
				break;
			}
		}
		cout << n << endl;
	}	
	return 0;
}