#include <iostream>

using namespace std;

class Complex
{
	public:
		int i;
		int j;
		Complex(int i, int j);

		friend ostream& operator<<(ostream& out, const Complex& c)
		{
			out << c.i << " + " << c.j << "j" << endl;
			return out;
		}
		Complex(const Complex& c)
		{
			cout << "拷贝构造函数" << endl;
			this->i = c.i;
			this->j = c.j;
		}
		Complex& operator=(const Complex& c)
		{
			cout << "重载操作符=" << endl;
			Complex* ret = new Complex(c.i, c.j);
			return *ret;
		}
};
Complex::Complex(int i, int j)
{
	cout << "构造函数" << endl;
	this->i = i;
	this->j = j;
}

int main()
{
	Complex c(1, 2);
	cout << c << endl;
	cout << "yes" << endl;
	Complex c2(3, 4);
	c = c2;
	cout << c << endl;
	Complex c3(c);
	return 0;
}
