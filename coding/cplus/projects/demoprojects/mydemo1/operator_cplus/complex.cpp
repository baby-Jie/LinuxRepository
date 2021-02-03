#include "complex.h"
#include <iostream>
using namespace std;

Complex::Complex(int i, int j)
{
	this->i = i;
	this->j = j;
	cout << "构造函数" << endl;
}

Complex::Complex(const Complex& c)
{
	this->i = c.i;
	this->j = c.j;
	cout << "拷贝构造函数" << endl;
}
Complex::Complex()
{
	cout << "无参数构造函数" << endl;
}
Complex& Complex::operator=(const Complex& c)
{
	this->i = c.i;
	this->j = c.j;
	cout << "操作符=重载" << endl;
	return *this;
}
Complex Complex::operator+(const Complex& c1)
{
	return Complex(this->i + c1.i, this->j + c1.j);	
}

ostream& operator<<(ostream& out, const Complex& c)
{
	out << c.i << " + " << c.j << "j";
	return out;
}
