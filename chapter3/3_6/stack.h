#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _LINKED_LIST_STACK_2_H_
#define _LINKED_LIST_STACK_2_H_

struct StackNode_ 
{
	int value;
	struct StackNode_ * next;
};

typedef struct StackNode_* Node;

struct Stack_
{
	Node top;
};

typedef struct Stack_ * Stack;

void stack_init(Stack stack);

/*
	1. if returns false, means the stack is not empty
	2. if returns true, menas the stack is empty
*/
bool isEmpty(Stack stack);

void push(Stack* stack, int value);

/*
1.if returns true: means pop successfully
2.if returns fasle: means the stack is empty
*/
bool pop(Stack* stack, int* value);

void peek(Stack stack, int* value);

#endif