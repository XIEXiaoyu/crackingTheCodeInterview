#include <stdio.h>
#include <stdlib.h>

struct LSNode 
{
	int value;
	struct LSNode* next;
};

typedef struct LSNode* Node;

/*
functions: 1 to create a node of the linked list stack
		   2 the createed node can be head of the stack
*/
Node LSNodeCreate(int value);

//压栈
Node push(Node tail, int value);

//出栈
Node pop(Node tail, int* data);

//毁掉整个栈
void destroyLStack(Node tail);