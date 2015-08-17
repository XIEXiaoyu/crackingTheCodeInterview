#include <stdio.h>
#include <stdlib.h>

#include "delRevK.h"

//第一大部分：怎样构造链表

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

//5.解决2_5题
Node addTwoLists(Node head1, Node head2)
{
	Node head = NULL, end = NULL, append = NULL;
	Node temp1 = head1, temp2 = head2;
	int value = 0, left = 0, carry = 0;

	while(temp1 != NULL || temp2 != NULL) 
	{
		if(temp1 == NULL || temp2 == NULL)
		{
			if(temp1 == NULL)
			{
				append = (Node)malloc(sizeof(Node)*1);
				value = temp2->num + carry;
				left = value % 10;
				carry = value / 10;
				end->next = append;
				append->num = left;
				end = append;
				temp2 = temp2->next;
			}
			else
			{
				append = (Node)malloc(sizeof(Node)*1);
				value = temp1->num + carry;
				left = value % 10;
				carry = value / 10;
				end->next = append;
				append->num = left;
				end = append;
				temp1 = temp1->next;
			}
		}
		else
		{
			if(head == NULL)
			{
				value = temp1->num + temp2->num;
				left = value % 10;
				carry = value / 10;
				head = (Node)malloc(sizeof(Node)*1);
				head->num = left;
				end = head;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			else
			{
				append = (Node)malloc(sizeof(Node)*1);
				value = temp1->num + temp2->num + carry;
				left = value % 10;
				carry = value / 10;
				append->num = left;
				end->next = append;
				end = append;
				temp1 = temp1->next;
				temp2 = temp2->next;
			}
		}		
	}
	if(carry != 0)
	{
		append = (Node)malloc(sizeof(Node)*1);
		append->num = carry;
		end->next = append;
		append->next = NULL;
	}
	else
	{
		end->next = NULL;
	}
	
	return head;
}



