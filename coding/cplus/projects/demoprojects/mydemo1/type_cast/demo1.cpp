#include <iostream>
#include <typeinfo>
using namespace std;

void test_type_cast()
{
	double d = 3.1415926;
	auto a1 = static_cast<int>(d); // c语言中 可以隐式类型转换的用这种

	char ch[1024] = "abcd";

	int * p = reinterpret_cast<int*>(ch);
	cout <<  ch << endl;
	cout << p << endl;
	cout << typeid(a1).name() << endl;

}

int main()
{
	double d = 12.34;
	int a = 1;
	a = d;
	d = a;
	cout << a << endl;
	cout << d << endl;

	test_type_cast();
	return 0;
}
