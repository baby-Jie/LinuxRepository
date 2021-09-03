#include <stdio.h>

#pragma pack(1)
struct AA
{
	int a;
	char b;
	short c;
	char d;
};
#pragma pack()

int main()
{
	printf("%ld\n", sizeof(struct AA));
	return 0;
}
