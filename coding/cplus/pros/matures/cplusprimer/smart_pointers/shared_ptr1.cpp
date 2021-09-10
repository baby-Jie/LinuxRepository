#include <iostream>
#include <memory>

using namespace std;

int main()
{
	shared_ptr<int> p;
	cout << p.get() << endl;
	
	//cout << *p << endl;
	return 0;
}
