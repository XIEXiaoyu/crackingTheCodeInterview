#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

int main()
{  
	Queue queue = queue_new();

	enqueue(queue, node_new(1));
	printf("1.Simon node is %p\n", queue->rear);
	enqueue(queue, node_new(2));
	printf("1.Filoa node is %p\n", queue->rear);
	enqueue(queue, node_new(3));
	printf("1.Cindy node is %p\n", queue->rear);
	enqueue(queue, node_new(4));
	printf("1.Gateman node is %p\n", queue->rear);
	printf("queue len is %d\n", queue->len);

	printQueue(queue);

	int i = 0;
	LLQNode node;
	printf("5. node is %p\n", node);
	int len = queue->len;
	for(i = 0; i < len; i++)
	{
		printf("2. i is %d\n", i);
		dequeue(queue, &node);
		node_print(node);
		printf("2. %p\n", node);
		printf("\n");
		free(node);
	}
	printf("\n");


	return 0;
}