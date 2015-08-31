#include <stdio.h>
#include <stdlib.h>

#include "3_4_1.h"

Stack stack_ini(int quotaValue)
{
	Stack stack = (Stack)malloc(sizeof(Stack));
	stack->top = 0;
	stack->quota = quotaValue;
	return stack;
}

void push_stack(Stack stack, int value)
{
	//stack已经满了
	if(stack->top > stack->quota)
	{
		printf("the stack is full.\n");
	}
	//stack没有满
	else
	{
		stack->top++;
		stack->a[stack->top-1] = value;
	}
}

void pop(Stack stack, int* data)
{
	//stack空了
	if(stack->top == 0) 
	{
		printf("The stack is empty.\n");
	}
	else
	{
		*data = stack->a[stack->top-1];
		stack->top--;
	}
	return;
}

void move(Stack a, Stack c)
{
	int * data = (int*)malloc(sizeof(int));
	pop(a, data);
	push_stack(c, *data);
	return;
}

void hanoi(	Stack a, 
			Stack b, 
			Stack c,
			int disks)
{
	if(disks == 1)
	{
		move(a,c);	
		printf("%c to %c")
		return;
	}

	//1.把一个N-1层的汉诺塔从初始的位置挪到目标位置
	hanoi(a, c, b, disks-1);

	//2.把原来位置的最后一层挪到目标位置
	move(a, c);

	//3.把N-1层汉诺塔从原来的空白位置挪到目标位置。
	hanoi(b, a, c, disks-1);
	return;

}