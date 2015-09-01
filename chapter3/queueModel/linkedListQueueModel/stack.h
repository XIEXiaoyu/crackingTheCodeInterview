#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct Node_ {
	int id;
	char name[16];
	struct Node_ * next;
};

typedef Node_* Node;

struct Queue_ {
	Node head;
	Node Rear;
	int len;
	bool is_inited;
};

typedef Queue_ * Queue;

//create a new node
Node node_new(int id, char* name);

//print the information of a node
void node_print(Node node);

//create a queue
Queue queue_new(void);

//judge if the queue is empty
bool queue_is_empty(Queue queue);

//add an element into the queue
void enqueue(Queue queue, Node node);

//remove an element from a queue and get the element
bool dequeue(Queue queue, Node* node);

//traverse the queue to print elements
void printQueue(Queue queue);

//delete and free all the elements from the queue
void clear_queue(Queue queue);

//destroy the queue
void freeQueue(Queue queue);