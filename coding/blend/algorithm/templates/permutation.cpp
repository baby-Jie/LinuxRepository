#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(vector<int>& v, int x, int y)
{
    int sum = v[x] + v[y];
    v[x] = sum - v[x];
    v[y] = sum - v[x];
}

void permutation(vector<int>& v, int start, int end)
{
    if (start >= end)
    {
        print(v);
        return;
    }
    for (int i = start; i <= end; i++)
    {
        swap(v, start, i);
        permutation(v, start+1, end);
        swap(v, start, i);
    }
}

int main()
{
    vector<int> v = {1,2, 3, 4};
    permutation(v, 0, 3);
    return 0;
}