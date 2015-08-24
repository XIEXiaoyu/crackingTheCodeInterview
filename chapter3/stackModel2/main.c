//这是一个顺序栈
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv)
{
	Stack stack = stack_ini();
	push(stack, 5);
	push(stack, 6);
	push(stack, 7);
	push(stack, 8);
	push(stack, 9);
	for(int i = 0; i < stack->top; i++)
	{
		printf("%d", stack->a[i]);
	}
	printf("\n");
	printf("top is %d\n", stack->top);

	int* data = (int*)malloc(sizeof(int));
	pop(stack, data);
	pop(stack, data);
	pop(stack, data);
	printf("pop is %d\n", *data);

	return 0;
}