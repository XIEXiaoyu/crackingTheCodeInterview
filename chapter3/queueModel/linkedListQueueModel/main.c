#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

int main()
{  
	Queue queue = queue_new();

	enqueue(queue, node_new(1, "Simon"));
	printf("1.Simon node is %p\n", queue->rear);
	enqueue(queue, node_new(2, "Fiola"));
	printf("1.Filoa node is %p\n", queue->rear);
	enqueue(queue, node_new(3, "Cindy"));
	printf("1.Cindy node is %p\n", queue->rear);
	enqueue(queue, node_new(4, "Gateman"));
	printf("1.Gateman node is %p\n", queue->rear);
	printf("queue len is %d\n", queue->len);

	printQueue(queue);

	int i = 0;
	Node node = (Node)malloc(sizeof(struct Node_));
	int len = queue->len;
	for(i = 0; i < len; i++)
	{
		printf("2. i is %d\n", i);
		dequeue(queue, &node);
		printf("2. the out node is \n");
		node_print(node);
		printf("2. %p\n", node);
		printf("2. \n");
		free(node);
	}
	printf("\n");

	printf("Now clear the queue\n");
	clear_queue(queue);
	freeQueue(queue);

	printQueue(queue);




	return 0;
}