#include <stdio.h>
#include <stdlib.h>

#include "2_5_3.h"


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