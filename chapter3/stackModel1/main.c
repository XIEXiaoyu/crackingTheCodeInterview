//这是一个链栈
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv)
{
	Node node = LStackCreate(1);
	printf("%d %p %p \n", node->value, node, node->next);

	node = push(node, 2);
	printf("%d %p %p\n", node->value, node, node->next);

	node = push(node, 3);
	printf("%d %p %p\n", node->value, node, node->next);


	int* data = (int*)malloc(sizeof(int));	
	Node poped = pop(node, data);
	printf("%d\n", *data);
	poped = pop(poped, data);
	printf("%d\n", *data);

	destroyLStack(poped);

	return 0;
}