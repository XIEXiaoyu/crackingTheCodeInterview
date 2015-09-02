/*
	to implement a circular queue
	1. if count == 0, means the queue is empty.
	2. if count == 20, menas the queue is full.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

int main()
{
	Queue queue = Queue_init();

	bool isEnqueued = Enqueue(queue, 15);

	QElementType* value = (QElementType*)malloc(sizeof(int));
	bool isDequeued = Dequeue(queue, value);

	for(int i = 0; i < MAXSIZE; i++)
	{
		isEnqueued = Enqueue(queue, i);

		if(isEnqueued == true){
			printf("%d Ok.\n", i);
		}
		else
		{
			printf("%d Full.\n",i);
		}
	}

	printf("%d\n", queue->front);

	for(int i = 0; i < MAXSIZE; i++)
	{
		isDequeued = Dequeue(queue, value);
 		if(isDequeued == true)
 		{
 			printf("%d\n", *value);
 		}
	}

	return 0;
}