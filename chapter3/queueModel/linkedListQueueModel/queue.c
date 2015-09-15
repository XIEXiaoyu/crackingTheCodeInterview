#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "queue.h"

Node node_new(int id, char* name)
{
	Node node = (Node)malloc(sizeof(struct Node_));
	if(node == NULL)
	{
		printf("error: fail to assign memory to node.\n");
		return NULL;
	}
	node->id = id;
	strncpy(node->name, name+0, 10); 
	node->next = NULL;
	return node;
}

void node_print(Node node)
{
	printf("id is %d, name is %s\n", node->id, node->name);
}

Queue queue_new(void)
{
	Queue queue = (Queue)malloc(sizeof(struct Queue_));
	if(queue == NULL)
	{
		printf("error: fail to assign memory to node.\n");
		return NULL;
	}
	Node head = node_new(-1, "head");
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

void enqueue(Queue queue, Node node)
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

bool dequeue(Queue queue, Node* node)
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

	Node node = queue->head->next;
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

	Node node = queue->head->next;
	Node temp;
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