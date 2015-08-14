#include <stdio.h>
#include <stdlib.h>

struct listNode {
	int num;
	struct listNode* next;
};

typedef struct listNode* Node;

Node nodeCreate(int number);

Node listAppend(Node head, int number);

Node listSearch(Node head, int number);

Node nodeDel(Node head, Node node);

int FindQuantity(Node head);

Node FindNodeByIndex(Node head, int index);