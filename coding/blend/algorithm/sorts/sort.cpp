#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
	int sum = a + b;
	a = sum - a;
	b = sum - a;
}

void print(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
			}
		}
	}
}

void selectSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				swap(a[i], a[j]);
			}
		}
	}
}

void quickSort(int a[], int start, int end)
{
	if (start >= end) return;
	int left = start, right = end;
	int key = a[left];
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];

		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;

	quickSort(a, start, left - 1);
	quickSort(a, left + 1, end);
}

void mergeSort(int a[], int start, int end)
{
	if (start >= end)	return;
	int middle = (start + end) / 2;

	mergeSort(a, start, middle);
	mergeSort(a, middle + 1, end);

	int n = end - start + 1;
	int* tempA = new int[n];
	int index = 0, index1 = start, index2 = middle+1;
	while (index1 <= middle && index2 <= end)
	{
		if (a[index1] < a[index2])	tempA[index++] = a[index1++];
		else	tempA[index++] = a[index2++];
	}
	while (index1 <= middle)
	{
		tempA[index++] = a[index1++];
	}
	while (index2 <= end)
	{
		tempA[index++] = a[index2++];
	}
	for (index = 0; index < n; index++)
	{
		a[index+start] = tempA[index];
	}
	delete []tempA;
}

int main()
{
	int a[] = {3, 6, 1, 9, 0, 7, 4, 5, 2, 8};

	int n = sizeof(a) / sizeof(int);
	//bubbleSort(a, n);
	//selectSort(a, n);
	//quickSort(a, 0, n - 1);
	//mergeSort(a, 0, n - 1);
	
	print(a, n);
	return 0;
}
