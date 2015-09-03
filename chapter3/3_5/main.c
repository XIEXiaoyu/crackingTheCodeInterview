#include <stdio.h>

#include "stack.h"
#include "3_5.h" 

int main(int argc, char* argv[])
{
	Node tail1 = LSNodeCreate(1);
	tail1 = enque(tail1, 2);
	tail1 = enque(tail1, 3);
	tail1 = enque(tail1, 4);
	tail1 = enque(tail1, 5);
	tail1 = enque(tail1, 6);
	tail1 = enque(tail1, 7);
	tail1 = enque(tail1, 8);

	Node tail2 = NULL; 

	// struct dequeueOutput dOutput = dequeue(tail1, tail2);
	// printf("%d\n", dOutput.popedValue);
	// dOutput = dequeue(dOutput.tail1, dOutput.tail2);
	// printf("%d\n", dOutput.popedValue);

	struct dequeueOutput temp;
	temp = dequeue(tail1, tail2);
	while(temp.tail2 != NULL)
	{
		temp = dequeue(temp.tail1, temp.tail2);
		printf("%d\n", temp.popedValue);
	}




	return 0;
} 
