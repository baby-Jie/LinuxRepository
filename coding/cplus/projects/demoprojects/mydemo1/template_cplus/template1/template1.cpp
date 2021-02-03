#include <iostream>
using namespace std;

template<typename T>
T mytest(T a, T b)
{
	cout << "this is template method" << endl;
	return a + b;
}

int mytest(int a, int b)
{
	cout << "this is normal method mytest" << endl;
	return a + b;
}

template<typename T>
T mytest1(T a, T b)

int main()
{

	int ret1 = mytest(1, 4); // 如果普通函数和模板函数都符合调用，那么优先调用普通函数，如果模板函数能够更好的匹配，那么会调用模板函数。
	int ret = mytest<>(1, 4); // 强制调用模板函数
	cout << ret << endl;
	return 0;
}
