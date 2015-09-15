#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _SQUEUE_
#define _SQUEUE_

#define MAXSIZE 20
typedef int QElementType;

struct Queue_ 
{
	QElementType data[MAXSIZE];
	int front, rear;
	int count; 
};

typedef struct Queue_ * Queue;

/*   
    initialise a queue
    1. if returns NULL, means the malloc is fail.
    2. if returns not NULL, means initialisation is successful.
*/
Queue Queue_init();

/*
    insert an element into the queue
	1. if returns fasle, means the queue is full
	2. if returns true, menas enqueue successfully
*/
bool Enqueue(Queue queue, QElementType value);

/*
	put out an element from the queue
	1. if returns false, means the queue is empty
	2. if returns true, means dequeue successfully
*/
bool Dequeue(Queue queue, QElementType* value);




#endif