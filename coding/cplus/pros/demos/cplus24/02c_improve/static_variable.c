#include <stdio.h>

void test1()
{
	static int a = 3;
	a++;
	printf("%d\n", a);
}

void test2()
{
	static int a;
	printf("%d\n", a);
}

int main()
{
	test1();
	test1();
	test2();
	return 0;
}
