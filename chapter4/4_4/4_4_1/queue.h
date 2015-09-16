#include <stdio.h>
#include <stdlib.h>

#ifndef __4_4_1_QUEUE_H__
#define __4_4_1_QUEUE_H__

#include "bst.h"
#include "list.h"

/*	queue node 结构体
	：每个node是一个List指针，
*/

struct QueueNode 
{
	List data;
	struct QueueNode* next;
};

typedef struct QueueNode* QueueNode;

/* 	queue 结构体
	： 有head和rear
*/
struct Queue
{
	QueueNode head;
	QueueNode rear;
};

typedef struct Queue* Queue;

/*	创建queue node
	argu: List
	retn: QueueNode
*/
QueueNode createQueueNode(List data);

/*	创建一个queue
	: argu: void
	: retn: Queue
	: head = rear = NULL;
*/
Queue createQueue(void);

/* enqueue
	: argu: Queue*
	: argu: QueueNode
	: retn: 利用 Queue*
*/
void enqueue(Queue* queue, QueueNode queueNode);

/* dequeue 每dequeue一个node，就是一个List，将来可用于打印list
	: argu: Queue* queue
	: argu: QueueNode*
	: retn: 利用QueueNode*
*/
void dequeue(Queue* queue, QueueNode* queueNode);

#endif