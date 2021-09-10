#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;

vector<vector<int>> result;
vector<int> v;
int target = 0;

void fun(int index, vector<int> preList)
{
    if (preList.size() > 3)    return;
    if (index >= v.size())  return;
    if (preList.size() == 3 && accumulate(preList.begin(), preList.end(), 0) == target)
    {
        result.push_back(vector<int>(preList));
        return;
    }
    fun(index+1, preList);
    int val = v[index];
    preList.push_back(val);
    fun(index+1, preList);
}

int main()
{
    v = {-1, 0, 1, 2, -1, -4};

    int ret = accumulate(v.begin(), v.end(), 0);
    // cout << ret << endl;
    fun(0, vector<int>());
    // cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++)
    {
        vector<int> tv = result[i];
        for (int j = 0; j < tv.size(); j++)
        {
            cout << tv[j] << " ";
        }
        cout << endl;
    }
    return 0;
}