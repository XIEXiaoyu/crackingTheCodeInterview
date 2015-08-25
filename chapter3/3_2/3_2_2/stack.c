#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

Node LStackCreate(MStack mstack, int value)  
{
	Node node = (Node)malloc(sizeof(Node)); 
	node->value = value;
	node->next = NULL;

	//对另一个存最小值的stack进行修改
	mstack = MPush(mstack, value);

	return node;
}

Node push(Node LSHead, int value, MStack* mstack)
{
	printf("1. mstack pointer is %p\n", mstack);
	Node node = (Node)malloc(sizeof(Node));
	node->value = value;
	node->next = LSHead;

	//对另一个存最小值的stack进行修改
	if(value < (*mstack)->value)
	{
		*mstack = MPush(*mstack, value);
		printf("3. mstack pointer is %p\n", *mstack);
	}

	return node;
}

Node pop(Node LSHead, int* data, MStack* mstack, int** mData)
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
			//首先对另一个存最小值的stack进行修改
			*mstack = MPop(*mstack, *mData);

			//再对原数组修改
			free(LSHead);
			return NULL;
		}
		//如果是一个普通的stack
		else
		{
			//首先对另一个存最小值的stack进行修改
			if(*data <= (*mstack)->value)
			{
				*mstack = MPop(*mstack, *mData);
			}

			//再对原数组修改
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

void getMin(MStack mstack, int* minimum)
{
	if(mstack->end == -1)
	{
		printf("It is a empty stack.\n");
	}
	else
	{
		*minimum = mstack->value;
	}	
}


