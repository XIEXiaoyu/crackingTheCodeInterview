#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "3_6.h"

int main(int argc, char* argv[])
{
	Stack stack1 = stack_init();

	int array[] = {5, 3, 4, 2, 8, 7, 9, 6, 2, 1};	
	for(int i = 0; i < 10; i++)
	{
		push(&stack1, array[i]);
	}

	Stack stack2 = stack_init();

	bool isStack1Storted = sort_stack(stack1, &stack2);

	if(isStack1Storted == true)
	{
		printf("sorted OK.\n");
	}

	int value;
	bool isStack2Poped; 

	while(stack2->top != NULL)
	{
		isStack2Poped = pop(&stack2, &value);
		if(isStack2Poped == true)
		{
			printf("%d\n", value);
		}		
	}

	return 0;
}