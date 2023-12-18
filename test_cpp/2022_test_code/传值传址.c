void foobar(int a, int *b, int **c)
{
	int *p = &a;
	*p = 101;
	*c = b;
	b = p;
}
 
int main()
{
	int a = 1;
	int b = 2;
	int c = 3;
	int *p = &c;
	foobar(a, &b, &p);
	printf("a=%d, b=%d, c=%d, *p=%d\n", a, b, c, *p);
	return (0);
}