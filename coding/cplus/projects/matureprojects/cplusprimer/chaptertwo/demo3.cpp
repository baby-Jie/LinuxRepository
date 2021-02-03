#include <iostream>
#include <typeinfo>
using namespace std;

class MyClassA {
	int a;
};


int main()
{
	int a = 0;
	unsigned int b = 1;
	signed int a1 = 0;
	char c = 97;
	unsigned char c1 = 97;
	signed char c2 = 97;
	double d = 1.0d;
	float f = 1.0f;
	long l = 1L;
	unsigned long l1 = 1L;
	long long ll = 1L;
	unsigned long long ll1 = 1L;

	char16_t ch1 = u'1';
	char32_t ch2 = U'1';
	wchar_t ch3 = L'1';

	cout << typeid(a).name() << endl; // i int
	cout << typeid(b).name() << endl; // j unsigned int  
	cout << typeid(a1).name() << endl;// i  signed int
	cout << typeid(c).name() << endl; // c char
	cout << typeid(c1).name() << endl;// h unsigned char
	cout << typeid(c2).name() << endl;// a
	cout << typeid(d).name() << endl; // d
	cout << typeid(f).name() << endl; // f
	cout << typeid(l).name() << endl; // l long
	cout << typeid(l1).name() << endl;// m unsigned long
	cout << typeid(ll).name() << endl;// x long long
	cout << typeid(ll1).name() << endl;// y unsigned long long 

	MyClassA custom_a = MyClassA();
	cout << typeid(custom_a).name() << endl;

	cout << typeid(ch1).name() << endl; // Ds
	cout << typeid(ch2).name() << endl; // Di
	cout << typeid(ch3).name() << endl; // w
	
	return 0;
}
