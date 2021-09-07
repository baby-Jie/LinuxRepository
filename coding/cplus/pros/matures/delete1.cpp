#include <iostream>

using namespace std;

int main()
{
	int* p = new int[3]{1, 2, 3};
	delete[]p;
	return 0;
}
