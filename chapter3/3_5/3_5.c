#include <stdio.h>

#include "stack.h"
#include "3_5.h"

Node enque(Node tail1, int value)
{
	Node new = push(tail1, value);
	return new; 
}

struct dequeueOutput dequeue(Node tail1, Node tail2)
{
	int* data = (int*)malloc(sizeof(int));
	struct dequeueOutput dOutput;

	if(tail2 == NULL)
	{
		Node temp = tail1;
		while(tail1 != NULL)
		{
			tail1 = pop(tail1, data);
			tail2 = push(tail2, *data); 
		}		
	}

	tail2 = pop(tail2, data);
	dOutput.tail1 = tail1;
	dOutput.tail2 = tail2;
	dOutput.popedValue = *data;

	return dOutput;
}