#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* PetName;
typedef int EnterTime;

//'c' for cat, and 'd' for dog
typedef char animalKind;

// 0 for not distinguish dog or cat, 1 for cat, -1 for dog
typedef int dequeuetype;  

struct NodeAnimal 
{
	PetName name;
	EnterTime t; // for example, 2 means today, then 1 menas yesterday
	struct NodeAnimal* next;
};
typedef struct NodeAnimal* NodeAnimal;

struct QueueAnimal
{
	NodeAnimal head;
	NodeAnimal front;
	NodeAnimal rear;
};
typedef struct QueueAnimal* QueueAnimal;

struct QueueWhole
{
	QueueAnimal catQueue;
	QueueAnimal dogQueue;
};
typedef struct QueueWhole* QueueWhole;

NodeAnimal nodeCreate(PetName name, EnterTime t);

QueueAnimal queue_animal_init();

/*
	1. if returns true, means the queue is empty
	2. if rtturns false, means the queue is not empty
*/
bool isQueueAnimalEmtpy(QueueAnimal queue_animal);

QueueWhole QueueWhole_init();

void enqueue_to_queue_animal(QueueAnimal* queue_animal, NodeAnimal node);

/*	
  	must indicate what kind of animals is inserted. 
 
 	if char animal is 'c', then will insert the cat into the cat queue
	if char animal is 'd', then will insert the dog into the dog queue
*/
void enqueue_to_queue_whole(QueueWhole* queue_whole, char animal, PetName name, EnterTime t);

bool dequeue_from_animal_queue_name(QueueAnimal* queue_animal, PetName* name);

bool dequeue_from_animal_queue_node(QueueAnimal* queue_animal, NodeAnimal* node);

/*
1. Through the second argument name we got the pet name;

2.	dequeuetype type = 1: deque cat
	dequeuetype type = -1: deguq dog
	dequeuetype type = 0: either cat or dog
*/
bool dequeue_from_queue_whole(QueueWhole *queueWhole, PetName* name, dequeuetype type);