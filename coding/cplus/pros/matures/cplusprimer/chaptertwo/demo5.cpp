#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
void pt(T t)
{
	cout << typeid(t).name() << endl;
}

int main()
{
	char16_t ch = 'a';
	auto ch1 = u'a';
	auto ch2 = U'a';
	auto ch3 = L'a';
	pt(ch);
	pt(ch1); // Ds
	pt(ch2); // Di
	pt(ch3); //
	cout << sizeof(ch) << endl;
	cout << sizeof(ch2) << endl;
	cout << sizeof(ch3) << endl;
	return 0;
}
