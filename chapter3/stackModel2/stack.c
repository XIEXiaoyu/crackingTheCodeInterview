#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Stack stack_ini()
{
	Stack stack = (Stack)malloc(sizeof(Stack));
	stack->top = 0;
	return stack;
}

Stack push(Stack stack, int value)
{
	if(stack->top == 0)
	{
		stack->top = 1;
		stack->a[stack->top-1] = value;
	}
	else
	{
		stack->a[stack->top] = value;
		stack->top++;
	}

	return stack;
}

/* ?这个函数返回的int, 不需要接吗？ */
int pop(Stack stack, int* data)
{
	if(stack->top == 0)
	{
		printf("It's already a empty stack.\n");
	}
	else
	{

		*data = stack->a[stack->top-1];
		stack->top--;	
	}
	return 1;	
}