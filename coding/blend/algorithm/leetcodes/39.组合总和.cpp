#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <vector>

using namespace std;

int target = 7;
vector<int> v = {2, 3, 6, 7};
vector<vector<int>> result;

void fun(int index, vector<int> preList, int sum)
{
    if (index >= v.size())  return;
    if (sum == target)
    {
        result.push_back(preList);
        return;
    }

    int val = v[index];
    while (sum < target)
    {
        fun(index+1, preList, sum);  
        preList.push_back(val);
        sum += val;
        if (sum == target)
        {
            result.push_back(preList);
        }
    }
}

int main()
{
    vector<int> preList;
    fun(0, preList, 0);

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