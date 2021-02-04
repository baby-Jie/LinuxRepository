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
	auto a1 = 2147483647; // 2^31 - 1
	pt(a1); //  i -> int 
	auto a2 = 2147483648; // 2^31
	pt(a2); // l -> long 
	auto a3 = 0x80000000; // 2^31 16进制
	pt(a3); // j -> unsigned int
	auto a4 = 020000000000; // 2^31 8进制
	pt(a4); // j -> unsigned int

	
	return 0;
}
