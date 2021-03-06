#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

LLQNode node_new(ElemTyp data)
{
	LLQNode node = (LLQNode)malloc(sizeof(struct LLQNode));
	if(node == NULL)
	{
		printf("error: fail to assign memory to node.\n");
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;
}

void node_print(LLQNode node)
{
	printf("data is %d\n", node->data);
}

Queue queue_new(void)
{
	Queue queue = (Queue)malloc(sizeof(struct Queue));
	if(queue == NULL)
	{
		printf("error: fail to assign memory to node.\n");
		return NULL;
	}
	LLQNode head = node_new(-1);
	queue->head = head;
	queue->rear = queue->head;
	queue->len = 0;
	queue->is_inited = true;
	return queue; 
}

bool queue_is_empty(Queue queue)
{
	if(queue->is_inited != true)
	{
		printf("The queue is not inited yet.\n");
		return false;
	}
	if(queue->head == queue->rear)
	{
		return true;
	}

	return false;
}

void enqueue(Queue queue, LLQNode node)
{
	if(queue->is_inited != true)
	{
		printf("the queue is not inited yet.\n");
		return;
	}

	queue->rear->next = node;
	queue->rear = node;
	node->next = NULL;
	queue->len++;

	return;
}

bool dequeue(Queue queue, LLQNode* node)
{
	if(queue->is_inited != true)
	{
		printf("The queue is not inited yet.\n");
		return false;
	}

	if(queue_is_empty(queue) == true)
	{
		printf("the queue is an empty queue.\n");
		return false;
	}
	
	*node = queue->head->next;
	queue->head->next = (*node)->next;
	queue->len--;

	if(queue->rear == *node)
	{
		queue->rear = queue->head;
		printf("now the left is an emtpy queue.\n");
	}
	
	return true;
}

void printQueue(Queue queue)
{
	if(queue->is_inited == false)
	{
		printf("the queue is not inited yet.\n");
		return;
	}

	if(queue_is_empty(queue) == true)
	{
		printf("the queue is empty.\n");
		return;
	}

	LLQNode node = queue->head->next;
	while(node != NULL)
	{
		node_print(node);
		node = node->next;
	}
}

void clear_queue(Queue queue)
{
	if(queue->is_inited != true)
	{
		printf("the queue is not inited yet.\n");
		return;
	}

	if(queue->head == queue->rear)
	{
		free(queue->head);
	}

	LLQNode node = queue->head->next;
	LLQNode temp;
	while(node != NULL)
	{
		temp = node;
		free(node);
		node = NULL;
		node = temp->next;
	}
	queue->rear = queue->head;
	queue->len = 0;
	return; 
}

void freeQueue(Queue queue)
{
	clear_queue(queue);
	free(queue->head);
	queue->head = NULL;
	free(queue);
	queue = NULL;
}