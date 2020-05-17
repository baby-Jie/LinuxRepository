#include <stdio.h>

int numPairDivisibleBy60(int* time, int timeSize)
{
	int totalCount = 0; // 总计数量
	for (int i = 0; i < timeSize - 1; i++)
	{
		for (int j = i + 1; j < timeSize; j++)
		{
			if ((time[i] + time[j]) % 60 == 0)
				totalCount++;
		}
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
