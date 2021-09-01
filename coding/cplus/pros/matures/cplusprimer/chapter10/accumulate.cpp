#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

using namespace std;

int main()
{
    
    vector<int> v;
    v.push_back(111);
    v.push_back(222);
    
    int ret = accumulate(v.begin(), v.end(), 0);
    cout << ret << endl;

    vector<double> v2;
    v2.push_back(1.6);
    v2.push_back(1.5);
    ret = accumulate(begin(v2), end(v2), 0);
    cout << ret << endl;

    vector<string> v3;
    v3.push_back("111"); 
    v3.push_back("222");
    string ret2 = accumulate(begin(v3), end(v3), string(""));
    cout << ret2 << endl;
    return 0;
    }
