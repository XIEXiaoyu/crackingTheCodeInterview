//这是一个链栈
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv)
{
	int array[] = {7, 6, 5, 4, 3, 2, 1};
	Node node = LStackCreate(array[0]);
	printf("node->value is %d\n", node->value);
	printf("node->min is %d\n\n", node->min);
	
	for(int i = 1; i < 7; i++)
	{
		node = push(node, array[i]);
		printf("node->value is %d\n", node->value);
		printf("node->min is %d\n\n", node->min);
	}

	int* data = (int*)malloc(sizeof(int));
	for(int j = 0; j < 6; j++)
	{
		node = pop(node, data);
		printf("poped data is %d\n", *data);
		printf("min now is %d\n\n", node->min);
	}

	destroyLStack(node);

	return 0;
}