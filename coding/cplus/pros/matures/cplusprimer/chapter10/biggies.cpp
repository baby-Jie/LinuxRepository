#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int main()
{
	vector<string> v;
	v.push_back("hello");
	v.push_back("my");
	v.push_back("name");
	v.push_back("is");
	v.push_back("smx");
	v.push_back("and");
	v.push_back("what's");
	v.push_back("your");
	v.push_back("name");
	sort(v.begin(), v.end());

	// unique, remove repeat items
	auto ret = unique(v.begin(), v.end());
	v.erase(ret, v.end());
	// sort items
	sort(v.begin(), v.end(), [](const string& str1, const string& str2)->bool{return str1.size() < str2.size();});

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}
