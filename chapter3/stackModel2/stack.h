#include <stdio.h>
#include <stdlib.h>

struct Stack_
{
	int a[20];
	int top;
};

typedef struct Stack_* Stack;


Stack stack_ini();

Stack push(Stack stack, int value);

int pop(Stack stack, int* data);
