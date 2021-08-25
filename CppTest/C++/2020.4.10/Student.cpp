#include <iostream>
#include <string.h>

#include <stdlib.h>
using namespace std;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "Student(int, char *)" << endl;
	}
	
	~Student()
	{
		delete [] _name;
		cout << "~Student" << endl; 
	}
	
	void print() const
	{
		cout << "_id " << _id << endl
			 << "_name " << _name << endl;
	}
	
	//重载之后的new
	void * operator new(size_t size)
	{
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);
		return ret;
	}
	//重载之后的delete
	void operator delete(void * ret)
	{
		cout << "void operator delete" << endl;
		free(ret);
	}
private:
	int _id;
	char * _name;	
};

int main(int argc, char *argv[]) 
{
	Student * pstu = new Student(100, "Jack");
	pstu->print();
	delete pstu;
	
	
	Student stu1(101, "Mary"); //栈对象
	stu1.print();
	
	return 0;
}