
struct student
{
	int age;
	char name[21];
	char sex;
};

int main()
{
	int a = (int)&((struct student *)0)->name;
	
}