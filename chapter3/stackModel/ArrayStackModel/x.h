#include <stdio.h>
#include <stdlib.h>

struct Stack_
{
	int a[20];
	int top;
};

typedef struct Stack_* Stack;


Stack stack_ini();

Stack push_stack(Stack stack, int value)

Stack pop(Stack stack, int* data)
