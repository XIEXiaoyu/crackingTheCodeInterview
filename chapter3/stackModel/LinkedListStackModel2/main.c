#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int main(int argc, char* argv[])
{
	Stack stack = (Stack)malloc(sizeof(struct Stack_));

	stack_init(stack);

	push(&stack, 1);

	push(&stack, 2);

	push(&stack, 3);

	int* data = (int*)malloc(sizeof(int));

	peek(stack, data);
	printf("%d\n", *data);

	pop(&stack, data);
	printf("%d\n", *data);

	pop(&stack, data);
	printf("%d\n", *data);

	pop(&stack, data);
	printf("%d\n", *data);

	printf("%p\n", stack->top);

	return 0;
}





