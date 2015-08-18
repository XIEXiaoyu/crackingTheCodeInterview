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

Nodum FindKthToLastNodeValueByIndex(Node head, int index)
{
	Nodum target = (Nodum)malloc(sizeof(Nodum) * 1);
	target->node = NULL;
	target->num = 1;
	Node temp;

	if(head == NULL)
	{
		return target;
	}
	else
	{
		target = FindKthToLastNodeValueByIndex(head->next, index);
		if(target->num == index)
		{
			target->node = head;
			target->num = target->num + 1;
			return target;

		}
		else
		{
			target->num = target->num + 1;
			return target;
		}
	}
}

int getLength(Node head)
{
	Node item = head;
	int length = 0;
	while(item != NULL)
	{
		length++;
		item = item->next;
	}
	return length;
}

Node addTwolistsFromTailToHead(Node head1, Node head2)
{
	int length1 = 0, length2 = 0, lengthShort, lengthLong;
	Node node1, node2, head, node, preNode;
	length1 = getLength(head1);
	length2 = getLength(head2);
	printf("3.1 lenght1 is %d and length2 is %d\n", length1, length2);
	if(length1 > length2)
	{
		lengthShort = length2;
		lengthLong = length1;
	}
	else
	{
		lengthShort = length1;
		lengthLong = length2;
	}

	printf("3.2 lengthshort is %d and lengthLong is %d\n\n", lengthShort, lengthLong);

	int value, left = 0, carry = 0;
	for(int i = 1; i <= lengthLong; i++)		
	{
		node1 = FindKthToLastNodeValueByIndex(head1, i)->node;
		node2 = FindKthToLastNodeValueByIndex(head2, i)->node;
		if(i <= lengthShort)			
		{
			node1 = FindKthToLastNodeValueByIndex(head1, i)->node;
			node2 = FindKthToLastNodeValueByIndex(head2, i)->node;
			printf("4. i is %d\n", i);
			printf("4.1 node1->num is %d and node2->num is %d\n", node1->num, node2->num);
			value = node1->num + node2->num + carry;
			left = value % 10;
			carry = value / 10;
			node = (Node)malloc(sizeof(Node)*1);
			node->num = left;
			if(i == 1)
			{
				node->next = NULL;
			}
			else
			{
				node->next = preNode;
			}
			preNode = node;			
		}
		else // when i >= lengthShort
		{
			if(length1 < length2)
			{					
				node2 = FindKthToLastNodeValueByIndex(head2, i)->node;
				value = node2->num + carry;				
			}
			else
			{
				node1 = FindKthToLastNodeValueByIndex(head1, i)->node;
				value = node1->num + carry;
			}
			left = value % 10;
			carry = value / 10;
			node = (Node)malloc(sizeof(Node)*1);
			node->num = left;
			node->next = preNode;
			preNode = node;
		}
	}
	if(carry != 0)
	{
		node = (Node)malloc(sizeof(Node)*1);
		node->num = left;
		node->next = preNode;	
	}
	return node;
}



