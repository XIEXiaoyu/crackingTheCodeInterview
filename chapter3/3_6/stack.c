#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

Stack stack_init()
{
	Stack stack = (Stack)malloc(sizeof(struct Stack_));
	stack->top = NULL;
	return stack;
}

bool isEmpty(Stack stack)
{
	bool isEmpty = false;
	if(stack->top == NULL)
	{
		return isEmpty = true;
	}
	return isEmpty;
}

void push(Stack* stack, int value)
{
	Node new = (Node)malloc(sizeof(struct StackNode_));
	new->value = value;
	new->next = (*stack)->top;
	(*stack)->top = new;
}

bool pop(Stack* stack, int* value)
{
	bool empty = isEmpty(*stack);
	if(empty == false)
	{
		Node poped = (*stack)->top;
		*value = poped->value;
		(*stack)->top = (*stack)->top->next;
		free(poped);
		return true;
	}
	else
	{
		return false;
	}
}

void peek(Stack stack, int* value)
{
	Node node = stack->top;
	*value = node->value;
}
