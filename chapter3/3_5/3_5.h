#include <stdio.h>

#include "stack.h"

#ifndef _TWOSTACKINTOQUEUE
#define _TWOSTACKINTOQUEUE

struct dequeueOutput
{
	Node tail1;
	Node tail2;
	int popedValue;
};

//enque
Node enque(Node tail1, int value);

//deuqe
struct dequeueOutput dequeue(Node tail1, Node tail2);

#endif