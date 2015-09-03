#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Node LSNodeCreate(int value) 
{
	Node node = (Node)malloc(sizeof(Node)); //?为什么是sizeof(Node), 不是sizeof(LSNode)
	node->next = NULL;
	node->value = value;
	return node;
}

Node push(Node tail, int value)
{	
	Node new = LSNodeCreate(value);
	new->next = tail;

	return new;
}

Node pop(Node tail, int* data)
{
	//如果是空stack
	if(tail == NULL)
	{
		printf("It is a empty stack already.\n");
		return NULL;
	}

	//如果不是空的
	else
	{
		*data = tail->value;
		//如果是只有一个元素的stack
		if(tail->next == NULL)
		{	
			free(tail);
			return NULL;
		}
		//如果是一个普通的stack
		else
		{
			Node temp = tail;
			tail = tail->next;
			temp->next = NULL;
			free(temp);
			return tail;
		}
	}
}

void destroyLStack(Node tail)
{
	while(tail != NULL)
	{
		Node temp = tail;
		int data = temp->value;
		tail = tail->next;
		free(temp);
		printf("%d is freed.\n", data);
	}
	printf("The whole stack is destroed.\n");
}
