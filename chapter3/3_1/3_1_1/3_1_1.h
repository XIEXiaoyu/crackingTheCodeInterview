#include <stdio.h>
#include <stdlib.h>

struct Stack_
{
	int* a;
	int top;
	int quota;
};
typedef struct Stack_ * Stack;

//压栈
Stack push_stack(Stack stack, int value);

//出栈
Stack pop(Stack stack, int* data);

