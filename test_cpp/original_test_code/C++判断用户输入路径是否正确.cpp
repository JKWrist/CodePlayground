#include <iostream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <tchar.h>
using namespace std;
string userPath;                     //用户输入路径
string TcharToChar(TCHAR * tchar);   //TCHAR转char函数，并存放在string中
string getDriveStrings();            //获取系统盘符字符串，返回string，形式为C:\\E:\\F:\\...
bool checkDrive(string drives, string userPath);   //检查用户输入路径盘符是否存在或合法，返回true或false
bool checkUserPath(string userPath);       //检查用户输入路径"\\"时候正确，不正确则给出提示，返回true或false
int main()
{
	bool isDriveExist;
	bool isUserPathRight;
	string drives = getDriveStrings();
	for (;;)
	{
		userPath = "";
		cout << "请输入文件路径:" << endl;
		cin >> userPath;
		isDriveExist = checkDrive(drives, userPath);
		if (!isDriveExist)
		{
			continue;
		}
		else
		{
			isUserPathRight = checkUserPath(userPath);
			if (!isUserPathRight)
			{
				continue;
			}
			else
			{
				cout << "路径合法！" << endl;
				break;
			}
		}
	}
}

string getDriveStrings()
{
	TCHAR szBuf[100];
	memset(szBuf, 0, 100);
	DWORD len = GetLogicalDriveStrings(sizeof(szBuf) / sizeof(TCHAR), szBuf);
	string s = TcharToChar(szBuf);
	return s;
}
 
string TcharToChar(TCHAR * tchar)
{
	string sz;
	for (TCHAR * s = tchar; *s; s += _tcslen(s) + 1)
	{
		char * _char = new char[100];
		int iLength;
		//获取字节长度    
		iLength = WideCharToMultiByte(CP_ACP, 0, s, -1, NULL, 0, NULL, NULL);
		//将tchar值赋给_char      
		WideCharToMultiByte(CP_ACP, 0, s, -1, _char, iLength, NULL, NULL);
		string t(_char);
		sz.append(t);
		free(_char);
	}
	return sz;
}

bool checkDrive(string drives, string userPath)
{
	int position;
	char driveTag = userPath.at(0);
	if (driveTag > 'a' && driveTag < 'z')
	{
		driveTag -= 32;
	}
	if ((driveTag > 'A' && driveTag<'Z') || (driveTag>'a' && driveTag < 'z'))
	{
		position = drives.find(driveTag);
		if (position == drives.npos)
		{
			cout << "输入的盘符不存在，请重新输入！" << endl;
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		cout << "输入盘符非法，请重新输入！" << endl;
		return false;
	}
}
 
bool checkUserPath(string userPath)
{
	bool isRight = true;
	string::iterator it;
	for (it = userPath.begin(); it != userPath.end(); ++it)
	{
		if (*it == '/')
		{
			isRight = false;
			cout << "\'/\'错误，应该为\'\\',请重新输入！" << endl;
			break;
		}
	}
	return isRight;
}
