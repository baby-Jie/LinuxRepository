#include <stdio.h>
#include "calc.h"

int main()
{
	int a = 10, b = 5;
	int ret = 0;
	ret = plus(a, b);
	printf("plus result: %d\n", ret);
	ret = subtract(a, b);
	printf("subtract result: %d\n", ret);
	ret = multiply(a, b);
	printf("multiply result: %d\n", ret);
	ret = div(a, b);
	printf("div result: %d\n", ret);
	printf("e_c: %d\n", e_c);
	return 0;
}
