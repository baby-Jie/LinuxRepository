#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
	Complex c(1, 2); // 执行构造函数
	Complex c2 = c; // 执行拷贝k构造函数
	c2 = c; // 执行=重载操作符函数
	Complex c3{1, 2}; // 这也是初始化 执行构造函数
	
	Complex c4 = c + c2; // 这里执行拷贝构造函数
	cout << c4 << endl;
	
	return 0;
}
