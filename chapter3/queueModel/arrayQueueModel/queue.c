#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

Queue Queue_init()
{
	Queue queue = (Queue)malloc(sizeof(struct Queue_));
	if(queue == NULL)
	{
		return NULL;
	}
	queue->front = 0;
	queue->rear = 0;
	queue->count = 0;
	return queue;
}

bool Enqueue(Queue queue, QElementType value)
{
	//if the queue is full
	if(queue->count == 20)
	{
		return false;
	}
	//queue is not full
	queue->data[queue->rear] = value;
	queue->rear = (queue->rear+1) % MAXSIZE;
	queue->count++;

	return true;
}

//put out an element from the queue
bool Dequeue(Queue queue, QElementType* value)
{
	//if the queue is empty
	if(queue->count == 0)
	{
		return false;
	}

	//if the queue is not empty
	*value = queue->data[queue->front];
	queue->count--;
	queue->front = (queue->front + 1) % MAXSIZE;

	return true;	
}