#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void printVector(vector<int>& v)
{
	// traverse method 1
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	// traverse method 2
//	for (auto it = v.begin(); it != v.end(); it++)
//	{
//		cout << *it << " ";
//	}
//	cout << endl;
}

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(2);
	v.push_back(4);
	v.push_back(2);

	printVector(v);	

	//v.erase(v.begin(), v.end());
	auto ret = remove(v.begin(), v.end(), 2);
	v.erase(ret, v.end());
	

	printVector(v);

	auto a = 11;
	cout << a << endl;
	cout << "hello" << endl;
	return 0;
}
