//这是一个链栈
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(int argc, char** argv)
{
	MStack mstack;
	mstack = MstackInit();

	int array[] = {7, 6, 5, 4, 3, 2, 1};
	Node node = LStackCreate(mstack, array[0]);
	printf("node->value is %d\n", node->value);
	printf("mstack->value = %d\n\n", mstack->value);

	node = push(node, array[1], &mstack);
	node = push(node, array[2], &mstack);
	node = push(node, array[3], &mstack);

	int* data = (int*)malloc(sizeof(int));
	int* mData = (int*)malloc(sizeof(int));

	node = pop(node, data, &mstack, &mData);

	int minimum;
	getMin(mstack, &minimum);
	printf("the minimum is %d\n", minimum);
	
	return 0;
}