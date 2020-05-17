#include <stdio.h>

int numPairDivisibleBy60(int* time, int timeSize)
{
	int ar[60] = {0};
	int totalCount = 0; // 总计数量
	for (int i = 0; i < timeSize; i++)
	{
		ar[time[i] % 60]++;
	}
	for (int i = 0; i < timeSize - 1; i++)
	{
		ar[time[i] % 60]--;
		totalCount += ar[(60 - (time[i] % 60)) % 60];
	}
	return totalCount;
}

int main()
{
	int time[] = {30, 20, 150, 100, 40};
	int ret = numPairDivisibleBy60(time, 5);
	printf("%d\n", ret);
	printf("hello\n");
	return 0;
}
