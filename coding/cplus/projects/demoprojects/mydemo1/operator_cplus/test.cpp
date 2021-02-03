#include <iostream>
using namespace std;

class A
{
	public:
		int i;
		A()
		{
			cout << "构造" << endl;
		}
		A(const A& a)
		{
			cout << "拷贝构造" << endl;
		}

		A test()
		{
			A a;
			return a;
		}
};
int main()
{
	A a;
	A b = a;
	return 0;
}
