#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"

ListNode createListNode(BstNode bstNode)
{
	ListNode listNode = (ListNode)malloc(sizeof(struct ListNode));
	listNode->data = bstNode;
	listNode->next = NULL;

	return listNode;
}

List createList(void)
{
	List list = (List)malloc(sizeof(struct List));
	list->head = list->rear = NULL;

	return list;
}

void insertList(List* list, ListNode listNode)
{
	if((*list)->head == NULL)
	{
		(*list)->head = (*list)->rear = listNode;
	}
	else
	{
		(*list)->rear->next = listNode;
		(*list)->rear = listNode;
	}
}

void printBstList(List list)
{
	ListNode temp = list->head;
	while(temp != NULL)
	{
		printf("%p\n", temp->data);
		temp = temp->next;
	}
	printf("end of list\n");
}

void printIntList(List list)
{
	ListNode temp = list->head;
	while(temp != NULL)
	{
		printf("%d\n", temp->data->data);
		temp = temp->next;
	}
	printf("end of list\n");
}