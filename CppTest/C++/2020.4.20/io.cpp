#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

void readConfig(const string & file)
{
	ifstream ifs(file);
	if(!ifs)
	{
		cout << "ifstream create error" << endl;
		return;
	}
	string key, value;
	string line;
	
	while(getline(ifs, line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " ---- > " << value << endl;
	}
	ifs.close();
}
int main(int argc, char *argv[]) 
{
	readConfig("server.conf");
}