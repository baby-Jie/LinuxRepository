#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	unsigned int u1 = 42, u2 = 10;
	cout << u1 - u2 << endl; // 32
	cout << u2 - u1 << endl; // 4294967264
	return 0;
}
