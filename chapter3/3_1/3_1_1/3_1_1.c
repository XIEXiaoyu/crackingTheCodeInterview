#include <stdio.h>
#include <stdlib.h>

#include "3_1_1.h"

Stack push_stack(Stack stack, int value)
{
	//stack已经满了
	if(stack->top >= stack->quota)
	{
		printf("the stack is full.\n");
	}
	//stack没有满
	else
	{
		stack->top++;
		stack->a[stack->top-1] = value;
	}
	return stack;
}

Stack pop(Stack stack, int* data)
{
	//stack空了
	if(stack->top == 0) 
	{
		printf("The stack is empty.\n");
		return stack;
	}
	else
	{
		*data = stack->a[stack->top-1];
		stack->top--;
		return stack;
	}
}