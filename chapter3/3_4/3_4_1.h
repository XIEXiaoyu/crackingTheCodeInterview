#include <stdio.h>
#include <stdlib.h>

#define N 3

struct Stack_
{
	int a[N];
	int top;
	int quota;
};

typedef struct Stack_* Stack;

Stack stack_ini(int quotaValue);

void push_stack(Stack stack, int value);

void pop(Stack stack, int* data);

void move(Stack a, Stack c);

void hanoi(	Stack present, 
			Stack blank, 
			Stack dest,
			int numberOfDisks);