#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "3_7.h"

NodeAnimal nodeCreate(PetName name, EnterTime t)
{   
	NodeAnimal node = malloc(sizeof(struct NodeAnimal));
	node->name = name;
	node->t = t;
	node->next = NULL;
	return node;	
}

QueueAnimal queue_animal_init()
{
	NodeAnimal head = nodeCreate("head", -1);
	QueueAnimal queue_animal = (QueueAnimal)malloc(sizeof(struct QueueAnimal));
	queue_animal->head = head;
	queue_animal->front = queue_animal->rear = head;

	return queue_animal;
}

bool isQueueAnimalEmtpy(QueueAnimal queue_animal)
{
	if(queue_animal->front == queue_animal->rear)
	{
		return true;
	}
	return false;
}

QueueWhole QueueWhole_init()
{
	QueueWhole queue_whole = (QueueWhole)malloc(sizeof(struct QueueWhole));
	queue_whole->catQueue = queue_animal_init();
	queue_whole->dogQueue = queue_animal_init();
	return queue_whole;
}

void enqueue_to_queue_animal(QueueAnimal* queue_animal, NodeAnimal node)
{
	(*queue_animal)->rear->next = node;
	(*queue_animal)->rear = node;
}

void enqueue_to_queue_whole(QueueWhole* queue_whole, char animal, PetName name, EnterTime t) 
{  
	NodeAnimal node = nodeCreate(name, t);
	if(animal == 'c') // insert into cat queue
	{
		enqueue_to_queue_animal(&((*queue_whole)->catQueue), node);
	}
	if(animal == 'd')  //insert into dog queue
	{
		enqueue_to_queue_animal(&((*queue_whole)->dogQueue), node);
	}
}

bool dequeue_from_animal_queue_name(QueueAnimal* queue_animal, PetName* name)
{
	if(isQueueAnimalEmtpy(*queue_animal) == true)
	{
		return false;
	}

	NodeAnimal node = (*queue_animal)->head->next;
	(*queue_animal)->head->next = node->next;
	strcpy(*name, node->name);
	return true;
}

bool dequeue_from_animal_queue_node(QueueAnimal* queue_animal, NodeAnimal* node)
{
	if(isQueueAnimalEmtpy(*queue_animal) == true)
	{
		return false;
	}

	*node = (*queue_animal)->head->next;  //? 可以free*node么？
	(*queue_animal)->head->next = (*node)->next;

	return true;	
}

/*
1. Through the second argument name we got the pet name;

2.	dequeuetype type = 1: deque cat
	dequeuetype type = -1: deguq dog
	dequeuetype type = 0: either cat or dog
*/
bool dequeue_from_queue_whole(QueueWhole *queueWhole, PetName* name, dequeuetype type)//do not tell cat or dog
{
	NodeAnimal node;
	NodeAnimal cat; 
	dequeue_from_animal_queue_node(&((*queueWhole)->catQueue), &cat);
	NodeAnimal dog; 
	dequeue_from_animal_queue_node(&((*queueWhole)->dogQueue), &dog);
	if(type == 1) //cat
	{
		if(isQueueAnimalEmtpy( (*queueWhole)->catQueue ) == true)
		{
			return false;
		}
		strcpy(*name, cat->name);  
		enqueue_to_queue_animal(&((*queueWhole)->dogQueue), dog);
	}
	else if(type == -1) //dog
	{
		if(isQueueAnimalEmtpy( (*queueWhole)->dogQueue ) == true)
		{
			return false;
		}
		strcpy(*name, dog->name);
		enqueue_to_queue_animal(&((*queueWhole)->catQueue), cat);
	}
	else //do not distinguish cat or dog
	{
	//如果两个queue都是空的，不能pop
		if(isQueueAnimalEmtpy( (*queueWhole)->catQueue ) == true && isQueueAnimalEmtpy( (*queueWhole)->dogQueue ) == true)
		{
			return false;
		}

		node = (cat->t <= dog->t) ? cat : dog;
		if(node == cat)
		{
			enqueue_to_queue_animal(&((*queueWhole)->dogQueue), dog);
		}
		else
		{
			enqueue_to_queue_animal(&((*queueWhole)->catQueue), cat);
		}
		strcpy(*name, cat->name);
	}

	return true;
}