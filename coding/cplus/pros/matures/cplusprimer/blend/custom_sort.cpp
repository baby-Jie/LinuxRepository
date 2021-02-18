#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool isShorter(string s1, string s2)
{
	return s1.size() < s2.size();
}

int main()
{
	vector<string> v;
	v.push_back("hello");
	v.push_back("yes");
	v.push_back("My");
	v.push_back("ab");
	// sort(v.begin(), v.end(), isShorter);
	stable_sort(v.begin(), v.end(), isShorter);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}
