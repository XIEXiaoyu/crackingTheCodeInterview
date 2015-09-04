#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

LinkedList init_list()
{
	LinkedList list = (LinkedList)malloc(sizeof(struct LinkedList));
	list->head = NULL;
	return list;
}

Node nodeCreate(int number) 
{   
	Node node = malloc(sizeof(struct listNode));
	node->num = number;
	node->next = NULL;
	return node;	
} 

void insert_node(LinkedList* list, int number) 
{  
	Node node = nodeCreate(number);
	node->next = (*list)->head;
	(*list)->head = node;
}

Node listSearch(LinkedList list, int number) 
{  
	Node target;
	Node item = list->head;
	while(item->num != number) {
		item = item->next;
	}
	target = item;
	return target;
}

bool nodeDel(LinkedList* list, Node node) 
{ 
	// 如果head是空的，就不能做删除node的操作
	if((*list)->head == NULL) 
	{
		return false;
	}

	// 不能删除无意的的node
	if(node == NULL)
	{
		return false;
	}

	// 删除了head
	else if(node == (*list)->head)
	{
		if(node->next == NULL) // 如果此时这个结点是唯一的一个结点
		{ 
			Node temp = node;
			(*list)->head = NULL;	
			free(temp);
		} 
		else  // 如果整个list不只有head，还有其他的node	
		{		
			Node temp = node;
			(*list)->head = node->next;
			free(temp);		
		}
		return true;
	}

	// 删除了一个不是head的普通结点
	else
	{
		Node beforeTarget = (*list)->head;
		while(beforeTarget->next != node && beforeTarget != NULL)
		{
			beforeTarget = beforeTarget->next;
		}
		if(beforeTarget == NULL)
		{
			return false; // the node is not in the list
		}
		else
		{
			beforeTarget->next = beforeTarget->next->next;
			free(node);
			return true;
		}
	}
}