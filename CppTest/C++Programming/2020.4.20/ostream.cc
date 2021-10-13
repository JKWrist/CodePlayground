#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

void test2()
{
	string file = "test.txt";
	ofstream ofs(file, std::ios::app);
	if(!ofs)
	{
		cout << "odstream create error !" << endl;
	}
	
	ofs << "this is first filename";
	
	ofs.close();
}

int main(int argc, char *argv[]) 
{
	test2();
	return 0;
}