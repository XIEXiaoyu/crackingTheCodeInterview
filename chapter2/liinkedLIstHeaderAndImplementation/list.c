#include <stdio.h>
#include <stdlib.h>

#include "list.h"

//1.生成一个node
Node nodeCreate(int number) {   
	Node node = malloc(sizeof(struct listNode));
	node->num = number;
	node->next = NULL;
	return node;	
} 

//2.向list的尾巴增加一个node
Node listAppend(Node head, int number) {  
	Node node = nodeCreate(number);
	Node item = head;
	while(item->next != NULL) {
		item = item->next;
	}
	item->next = node;
	return head;
}

//3.寻找一个node
Node listSearch(Node head, int number) {  
	Node target;
	Node item = head;
	while(item->num != number) {
		item = item->next;
	}
	target = item;
	return target;
}

//4.删除一个node
Node nodeDel(Node head, Node node) { 
	//1.如果head是空的
	if(head == NULL) 
	{
		return NULL;
	}

	//2.删除了head
	else if(node == head)
	{
		if(node->next == NULL) //2.1 如果此时这个结点是唯一的一个结点
		{ 
			free(head);
			head = NULL;
		} 
		else  //2.2 如果整个list不只有head，还有其他的node	
		{		
			Node temp = head;
			head = head->next;
			free(temp);		
		}
		return head;
	}

	//3.删除了tail，此时tail不是唯一的一个结点
	else if(node->next == NULL) 
	{
		Node target = head->next;
		while(target->next != node) 
		{
			target = target->next;
		}
		target->next = NULL;
		free(node);
		return head;
	}

	//4.删除了不是head或者tail的结点
	else 
	{
		Node target = head;
		while(target->next != node) 
		{
			target = target->next;
		}
		target->next = node->next;
		free(node);
		return head;
	}
}