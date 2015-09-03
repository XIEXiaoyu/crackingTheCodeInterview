#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"
#include "3_6.h"

bool sort_stack(Stack stack1, Stack* stack2)
{
	int valueForStack1;
	int valueForStack2;
	bool isStack1Poped;
	bool isStack2Poped;

	if(isEmpty(stack1) == true)
	{
		return false;
	}

	if(isEmpty(*stack2) == false)
	{
		return false;
	}
	else
	{
		isStack1Poped = pop(&stack1, &valueForStack1);
		push(stack2, valueForStack1);
	}
	

	while(stack1->top != NULL)
	{
		isStack1Poped = pop(&stack1, &valueForStack1);
		isStack2Poped = pop(stack2, &valueForStack2);

		if(valueForStack2 > valueForStack1)
		{
			while( (*stack2)->top != NULL && (valueForStack2 > valueForStack1) )
			{
				push(&stack1, valueForStack2);
				isStack2Poped = pop(stack2, &valueForStack2);
			}
			push(stack2, valueForStack2);
			push(stack2, valueForStack1);
		}
		else
		{
			push(stack2, valueForStack2);
			push(stack2, valueForStack1);
		}			
	}

	return true;
}