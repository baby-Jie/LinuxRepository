#include <stdio.h>
#include "MyStack.h"

int main()
{
	Stack stack;
	initial(&stack, 10);
	push(&stack, 1);
	push(&stack, 2);
	push(&stack, 3);

	int ret = pop(&stack);
	printf("ret:%d\n", ret);
	ret = pop(&stack);
	printf("ret:%d\n", ret);
	ret = pop(&stack);
	printf("ret:%d\n", ret);
	return 0;
}
