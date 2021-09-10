#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int getCapacity(vector<int>& v, int startIndex, int endIndex)
{
    int height1 = v[startIndex];
    int height2 = v[endIndex];
    return (endIndex - startIndex)*min(height1, height2);
}

int getMaxCapacity(vector<int>& v)
{
    int maxCapacity = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            int capacity = getCapacity(v, i, j);
            maxCapacity = max(maxCapacity, capacity);
        }
    }
    return maxCapacity;
}

int getMaxCapacity2(vector<int>& v)
{
    int startIndex = 0;
    int endIndex = v.size() - 1;

    int maxCapacity = getCapacity(v, startIndex, endIndex);

    while (startIndex < endIndex)
    {
        if (v[startIndex] < v[endIndex])
        {
            startIndex++;
        }
        else
        {
            endIndex--;
        }
        maxCapacity = max(maxCapacity, getCapacity(v, startIndex, endIndex));
    }

    return maxCapacity;
}

int main()
{
    vector<int> v = {1,8,6,2,5,4,8,3,7};
    cout << getMaxCapacity2(v) << endl;
    return 0;
}