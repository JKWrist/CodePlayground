#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
bool is_chinese(const string& str)
{
	unsigned char utf[4] = {0};
	unsigned char unicode[3] = {0};
	bool res = false;
	for(int i = 0; i < str.length(); i++) 
	{
		if ((str[i] & 0x80) == 0) 
		{
			//ascii begin with 0
				res = false;
		}
		else /*if ((str[i] & 0x80) == 1) */
		{
			utf[0] = str[i];
			utf[1] = str[i + 1];
			utf[2] = str[i + 2];
			i++;
			i++;
			unicode[0] = ((utf[0] & 0x0F) << 4) | ((utf[1] & 0x3C) >>2);
			unicode[1] = ((utf[1] & 0x03) << 6) | (utf[2] & 0x3F);
			//printf("%x,%x\n",unicode[0],unicode[1]);
			//printf("aaaa %x,%x,%x\n\n",utf[0],utf[1],utf[2]);
			if(unicode[0] >= 0x4e && unicode[0] <= 0x9f)
			{
				if (unicode[0] == 0x9f && unicode[1] >0xa5)
					res = false;
				else
					res = true;
			}
			else
				res = false;
		}
	}
	return res;
}

int main()
{
	string str="中国";
	string str1="asdasfdsfd";
	string str2="中国sdsds";
	cout << "111 " << is_chinese(str) <<endl;
	cout << "222 " << is_chinese(str1) <<endl;
	cout << "333 " << is_chinese(str2) <<endl;
	
	cout << str[0] << endl;
	return 0;
}
