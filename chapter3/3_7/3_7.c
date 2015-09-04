#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

NodeAnimal nodeCreate(PetName name, EnterTime t)
{   
	NodeAnimal node = malloc(sizeof(struct NodeAnimal));
	node->name = name;
	node->day = day;
	node->next = NULL;
	return node;	
}

// bool isQueueAnimalEmtpy(QueueAnimal queue_animal)
// {
// 	if(queue_animal->front == queue_animal->rear)
// 	{
// 		return true;
// 	}
// 	return false;
// }

// QueueAnimal queue_animal_init()
// {
// 	QueueAnimal head = nodeCreate("head", -1);
// 	QueueAnimal queue_animal = (QueueAnimal)malloc(sizeof(struct QueueAnimal));
// 	QueueAnimal->front = queue_animal->rear = head;

// 	return queue_animal;
// }

// QueueWhole QueueWhole_init()
// {
// 	QueueWhole queue_whole = (QueueWhole)malloc(sizeof(struct QueueWhole));
// 	queue_whole->catQueue = queue_animal_init();
// 	queue_whole->dogQueue = queue_animal_init();
// 	return queue_whole;
// }

// void enqueue_to_queue_animal(QueueAnimal* queue_animal, Node node)
// {
// 	node->next = (*queue_animal)->rear;
// 	(*queue_animal)->rear = node;
// }

// void enqueue_to_queue_whole(QueueWhole* queue_whole, char animal, PetName name, EnterTime t) 
// {  
// 	Node_animal node = nodeCreate(name, t);
// 	if(animal == 'c') // insert into cat queue
// 	{
// 		push_to_queue_animal(&((*queue_whole)->catQueue), node);
// 	}
// 	else  //insert into dog queue
// 	{
// 		push_to_queue_animal(&((*queue_whole)->dogQueue), node);
// 	}
// }

// bool dequeue_from_animal_queue_name(Queue_animal* queue_animal, PetName* name)
// {
// 	if(isQueueAnimalEmtpy(*queue_animal) == true)
// 	{
// 		return false;
// 	}

// 	NodeAnimal node = (*queue_animal)->head->next;
// 	(*queue_animal)->head->next = node->next;
// 	strcpy(*name, node->name);
// 	return true;
// }

// bool dequeue_from_animal_queue_node(Queue_animal* queue_animal, NodeAnimal* node)
// {
// 	if(isQueueAnimalEmtpy(*queue_animal) == true)
// 	{
// 		return false;
// 	}

// 	*node = (*queue_animal)->head->next;
// 	(*queue_animal)->head->next = node->next;

// 	return true;	
// }

// /*
// 1. Through the second argument name we got the pet name;

// 2.	dequeuetype type = 1: deque cat
// 	dequeuetype type = -1: deguq dog
// 	dequeuetype type = 0: either cat or dog
// */
// bool dequeue_from_queue_whole(QueueWhole *queueWhole, PetName* name, dequeuetype type)//do not tell cat or dog
// {
// 	//如果两个queue都是空的，不能pop
// 	if((*queueWhole)->dogQueue->head == NULL && (*queueWhole)->catQueue->head == NULL)
// 	{
// 		return false;
// 	}
// 	NodeAnimal cat = dequeue_from_animal_queue_node((*queueWhole)->catQueue, node);
// 	NodeAnimal dog = dequeue_from_animal_queue_node((*queueWhole)->dogQueue, node);

// 	if(type == 1) //cat
// 	{
// 		*name = cat->name;
// 		enqueue_to_queue_animal(&((*queueWhole)->dogQueue), dog);
// 	}
// 	else if(type = -1) //dog
// 	{
// 		*name = dog->name;
// 		enqueue_to_queue_animal(&((*queueWhole)->catQueue), cat);
// 	}
// 	else //do not distinguish cat or dog
// 	{
// 		*node = (cat->t > dog->t) ? cat : dog;
// 		if(*node == cat)
// 		{
// 			enqueue_to_queue_animal(&((*queueWhole)->dogQueue), dog);
// 		}
// 		else
// 		{
// 			enqueue_to_queue_animal(&((*queueWhole)->catQueue), cat);
// 		}
// 	}

// 	return true;
// }