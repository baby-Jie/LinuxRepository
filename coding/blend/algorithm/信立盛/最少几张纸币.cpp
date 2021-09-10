/*
题目：有面值为1 5 10 50 100 的纸币，分别为 a b c d e 张，给定一个k，求最少用多少张纸币能凑成k元，如果凑不成，返回-1
*/

#include <iostream>
#include <cmath>

using namespace std;

int n = 0;
int* array = nullptr;

int getMinNumber(int index, int target)
{
    if (target < 0)     return -1;
    if (target == 0)    return 0;
    if (index < 0)  return -1;

    int ret1 = getMinNumber(index-1, target);
    int ret2 = getMinNumber(index-1, target-array[index]);

    if (ret1 < 0 && ret2 < 0)
    {
        return -1;
    }
    if (ret1 < 0)
    {
        return ret2 + 1;
    }
    if (ret2 < 0)
    {
        return ret1;
    }
    return min(ret1, ret2+1);
}

int main()
{
    int a = 0, b = 0, c, d, e;
    int k;
    a = 10;
    b = 10;
    c = 10;
    d = 0;
    e = 10;
    int n = a + b + c + d + e;
    array = new int[n+1];
   

    int index = 1;
    array[0] = 0;
    for (int i = 0; i < a; i++)
    {
        array[index++] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        array[index++] = 5;
    }
    for (int i = 0; i < c; i++)
    {
        array[index++] = 10;
    }
    for (int i = 0; i < d; i++)
    {
        array[index++] = 50;
    }
    for (int i = 0; i < e; i++)
    {
        array[index++] = 100;
    }

    cin >> k;
    int ret =  getMinNumber(n, k);
    cout << ret << endl;
    if (array)
    {
        delete [] array;
        array = nullptr;
    }
    
    return 0;
}