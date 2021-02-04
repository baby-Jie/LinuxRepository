#include <iostream>

using namespace std;

int main()
{
	// 标识符: 字母、数字、下划线组成。不能以数字开头，不能连续出现两个下划线，也不能以下划线连着大写字母开头。此外，定义在函数体外的标识符不能以下划线开头。标识符的长度没有限制，但是大小写敏感。不能用关键字。
	int __a = 78;
	cout << __a << endl;
	int _A = 79;
	cout << _A << endl;
	return 0;
}
