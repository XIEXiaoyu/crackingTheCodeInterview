
#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>

struct listNode {
	int num;
	struct listNode* next;
};

typedef struct listNode* Node;

struct NodeAndNum {
	Node node;
	int num;
};

typedef struct NodeAndNum* Nodum;

Node nodeCreate(int number);

Node listAppend(Node head, int number);

Node listSearch(Node head, int number);

Node nodeDel(Node head, Node node);

#endif