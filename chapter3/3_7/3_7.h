#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
};
typedef struct NodeAnimal* NodeAnimal;

struct QueueAnimal
{
	QueueAnimal front;
	QueueAnimal rear;
};
typedef Queue_animal* QueueAnimal;

struct QueueWhole
{
	QueueAnimal catQueue;
	QueueAnimal dogQueue;
};
typedef QueueWhole* QueueWhole;

NodeAnimal nodeCreate(PetName name, EnterTime t);

// bool isQueueAnimalEmtpy(QueueAnimal queue_animal);

// QueueAnimal queue_animal_init();

// QueueWhole QueueWhole_init();

// void enqueue_to_queue_animal(QueueAnimal* queue_animal, Node node);

// void enqueue_to_queue_whole(QueueWhole* queue_whole, char animal, PetName name, EnterTime t);

// bool dequeue_from_animal_queue_name(Queue_animal* queue_animal, PetName* name);

// bool dequeue_from_animal_queue_node(Queue_animal* queue_animal, NodeAnimal* node);

// /*
// 1. Through the second argument name we got the pet name;

// 2.	dequeuetype type = 1: deque cat
// 	dequeuetype type = -1: deguq dog
// 	dequeuetype type = 0: either cat or dog
// */
// bool dequeue_from_queue_whole(QueueWhole *queueWhole, PetName* name, dequeuetype type);