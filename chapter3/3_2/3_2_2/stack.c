#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Node LStackCreate(int value)  
{
	Node node = (Node)malloc(sizeof(Node)); 
	node->value = value;
	node->next = NULL;
	return node;
}

Node push(Node LSHead, int value)
{
	Node node = (Node)malloc(sizeof(Node));
	node->value = value;
	node->next = LSHead;
	return node;
}

Node pop(Node LSHead, int* data)
{
	//如果是空stack
	if(LSHead == NULL)
	{
		printf("It is a empty stack already.\n");
		return NULL;
	}

	//如果不是空的
	else
	{
		*data = LSHead->value;
		//如果是只有一个元素的stack
		if(LSHead->next == NULL)
		{	
			free(LSHead);
			return NULL;
		}
		//如果是一个普通的stack
		else
		{
			Node temp = LSHead;
			LSHead = LSHead->next;
			temp->next = NULL;
			free(temp);
			return LSHead;
		}
	}
}

void destroyLStack(Node LSHead)
{
	while(LSHead != NULL)
	{
		Node temp = LSHead;
		int data = temp->value;
		LSHead = LSHead->next;
		free(temp);
		printf("%d is freed.\n", data);
	}
	printf("The whole stack is destroed.\n");
}


