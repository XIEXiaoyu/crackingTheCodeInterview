#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"
#include "queue.h"

QueueNode createQueueNode(List data)
{
	QueueNode queueNode = (QueueNode)malloc(sizeof(struct QueueNode));
	queueNode->data = data;
	queueNode->next = NULL;

	return queueNode;
}

Queue createQueue(void)
{
	Queue queue = (Queue)malloc(sizeof(struct Queue));
	queue->head = queue->rear = NULL;

	return queue;
}

void enqueue(Queue* queue, QueueNode queueNode)
{
	if((*queue)->head == NULL)
	{
		(*queue)->head = (*queue)->rear = queueNode;
	}
	else
	{
		(*queue)->rear->next = queueNode;
		(*queue)->rear = queueNode;
	}	
}

void dequeue(Queue *queue, QueueNode* queueNode)
{
	if((*queue)->head == NULL)
	{
		return;
	}

	if((*queue)->head == (*queue)->rear)
	{
		*queueNode = (*queue)->head;
		(*queue)->head = (*queue)->rear = NULL;

		return;
	}
	else{
		*queueNode = (*queue)->head;
		(*queue)->head = (*queue)->head->next; 

		return;
	}
}