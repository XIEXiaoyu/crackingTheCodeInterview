/*With this linked list queue model, we can specify the type of data*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _LINKQUEUE_GENERAL_H_  //if not define
#define _LINKQUEUE_GENERAL_H_

typedef  int ElemTyp;

struct LLQNode {
	ElemTyp data;
	struct LLQNode * next;
};

typedef struct LLQNode* LLQNode;

struct Queue {
	LLQNode head;
	LLQNode rear;
	int len;
	bool is_inited;
};

typedef struct Queue* Queue;

//create a new node
LLQNode node_new(ElemTyp data);

//print the information of a node
void node_print(LLQNode node);

//create a queue
Queue queue_new(void);

//judge if the queue is empty
bool queue_is_empty(Queue queue);

//add an element into the queue
void enqueue(Queue queue, LLQNode node);

//remove an element from a queue and get the element
bool dequeue(Queue queue, LLQNode* node);

//traverse the queue to print elements
void printQueue(Queue queue);

//delete and free all the elements from the queue
void clear_queue(Queue queue);

//destroy the queue
void freeQueue(Queue queue);

#endif