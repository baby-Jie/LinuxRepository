#ifndef __COMPLEX_H
#define __COMPLEX_H
#include <iostream>
using namespace std;
class Complex
{
	private:
		int i;
		int j;
	public:
		Complex(int i, int j);
		Complex(const Complex& c);
		Complex();
	public:
		Complex& operator=(const Complex& c);
		Complex operator+(const Complex& c);
		friend ostream& operator<<(ostream& out, const Complex& c);// 这里一定不要加const，否则报错
};
#endif
