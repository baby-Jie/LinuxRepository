#include "MyStack.h"
#include <stdio.h>
#include <stdlib.h>

int isEmpty(Stack* stack)
{
	return stack->size == 0;
}

// 初始化栈
void initial(Stack* stack, int capacity)
{
	stack->capacity = capacity;
	stack->arr = (int*)malloc(sizeof(int) * capacity);
	stack->size = 0;
}

void push(Stack* stack, int element)
{
	int size = stack->size;
	stack->arr[size] = element;
	stack->size++;
}

int pop(Stack* stack)
{
	if (isEmpty(stack))
	{
		return -1;
	}
	int ret = stack->arr[--stack->size];
	return ret;
}
