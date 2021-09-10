#include <iostream>
#include <limits.h>
using namespace std;

int findSecondMax(int a[], int length)
{
    if (length < 2) return INT_MIN;
    int max1, max2;

    if (a[0] > a[1])
    {
        max1 = a[0];
        max2 = a[1];
    }
    else
    {
        max1 = a[1];
        max2 = a[0];
    }
    for (int i = 2; i < length; i++)
    {
        int val = a[i];
        if (val > max1)
        {
            max2 = max1;
            max1 = val;
        }
        else if (val > max2)
        {
            max2 = val;
        }
    }
    return max2;
}

int main()
{
    int a[] = {4, 6, 2, 7, 1, 0, 9};
    int ret = findSecondMax(a, sizeof(a) / sizeof(int));
    cout << ret << endl;
    return 0;
}