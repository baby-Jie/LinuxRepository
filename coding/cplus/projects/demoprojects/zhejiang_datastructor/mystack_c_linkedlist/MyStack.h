#ifndef __MYSTACK_H
#define __MYSTACK_H

typedef struct MyStack
{
	int size;
	int capacity;
	int *arr;
} Stack;

// 返回栈是否为空
int isEmpty(Stack* stack);

// 初始化栈
void initial(Stack* stack, int capacity);

// 压栈
void push(Stack* stack, int element);

// 出栈
int pop(Stack* stack);

#endif
