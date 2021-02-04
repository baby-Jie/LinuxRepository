#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	Complex c1(1, 1);
	Complex c2(2, 3);
	Complex c3(3, 4);
	Complex ret1 = c1 + c2 + c3;
	cout << ret1 << endl;
	return 0;
}
