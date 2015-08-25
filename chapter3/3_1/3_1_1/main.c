#include <stdio.h>
#include <stdlib.h>
#include "3_1_1.h"

int main(int argc, char** argv)
{
	int a[100];

	Stack stack1 = (Stack)malloc(sizeof(struct Stack_));
	stack1->a = &a[0];  //这是重点
	stack1->quota = 10;

	printf("top is %d\n\n", stack1->top);
	int array[20] = {1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11, 12, 13};
	for(int i = 0; i < 11; i++)
	{
		stack1 = push_stack(stack1, array[i]);
		printf("top is %d\n", stack1->top);
		printf("a[stack->top-1] is %d\n\n", stack1->a[stack1->top-1]);
	}

	int* data = (int*)malloc(sizeof(int));
	for(int j = 0; j <= stack1->quota; j++)
	{
		stack1 = pop(stack1, data);
		printf("stack->a[stack->top-1] is %d\n", *data);
	}

	return 0;
}
