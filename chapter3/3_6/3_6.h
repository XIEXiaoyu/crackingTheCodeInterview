#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

/*
	1. the first argument 'stack1' is the input stack which needs to be sorted.
	2. the second argument 'stack2' is contains the sorted stack.
	3. the second argument 'stack2' must be given an empty stack at first. 
	4. if return false, means one of the below happens
		a) stack1 is an empty stack, can not sort it.
		b) stack2 is not empty when given as an input to function sort_stack()
	5. if returns true, means the sorting is successful.
*/
bool sort_stack(Stack stack1, Stack* stack2);
