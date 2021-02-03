#include <iostream>

using namespace std;

int main()
{
	unsigned int u = 10;
	int i = -42;
	cout << i + i << endl; // 同种类型不发生类型转换 输出-84
	cout << i + u << endl; // 不同类型运算，小范围变成大范围，无符号类型范围较大，所以结果式无符号类型，那么i将被当成无符号类型来计算，所以输出 4294967264
	return 0;
}
