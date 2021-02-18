#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{

	vector<string> v;
	v.push_back("abc");
	v.push_back("aav");
	v.push_back("bd");
	v.push_back("bd");
	sort(v.begin(), v.end());

	auto it = unique(v.begin(), v.end());
	v.erase(it, v.end());
	
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << "yes" << endl;
	return 0;
}
