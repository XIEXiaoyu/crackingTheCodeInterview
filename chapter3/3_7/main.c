#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "3_7.h"

int main(int argc, char* argv[])
{
	QueueWhole queue_whole = QueueWhole_init();

	enqueue_to_queue_whole(&queue_whole, 'c', "xiaoxiao", 1);
	enqueue_to_queue_whole(&queue_whole, 'c', "maomi", 2);
	enqueue_to_queue_whole(&queue_whole, 'c', "dabaimao", 3);

	enqueue_to_queue_whole(&queue_whole, 'd', "yeliqing", 3);
	enqueue_to_queue_whole(&queue_whole, 'd', "xiaolang", 5);
	enqueue_to_queue_whole(&queue_whole, 'd', "xiaomao", 7);


	PetName name = (PetName)malloc(sizeof(PetName));

	bool isdequeueSuc = dequeue_from_queue_whole(&queue_whole, &name, 0);
	if(isdequeueSuc == true)
	{
		printf("name is %s\n", name);
	}

	isdequeueSuc = dequeue_from_queue_whole(&queue_whole, &name, 0);
	if(isdequeueSuc == true)
	{
		printf("name is %s\n", name);
	}
	
	return 0;
}
