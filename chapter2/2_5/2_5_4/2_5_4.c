#include <stdio.h>
#include <stdlib.h>

#include "2_5_4.h"

Node recursiveAddTwolistsFromHeadToTail(Node head1, Node head2, int carry)
{
	if(head1 == NULL && head2 == NULL)
	{
		printf("5. carry is %d\n", carry);
		if(carry != 0)
		{
			Node tail = (Node)malloc(sizeof(Node) * 1);
			tail->num = carry;
			tail->next = NULL;
			return tail;
		}
		else
		{
			return NULL;
		}		
	}

	Node head = (Node)malloc(sizeof(Node) * 1);
	int value = 0, left = 0;
	if(head1 == NULL)
	{
		value = carry + head2->num; 
	}
	else if(head2 == NULL)
	{
		value = carry + head1->num;
	}
	else
	{
		value = head1->num + head2->num + carry;
	}

	left = value % 10;
	carry = value / 10;
	Node pre = (Node)malloc(sizeof(Node) * 1);
	pre->num = left;

	Node next = recursiveAddTwolistsFromHeadToTail(head1 == NULL ? NULL : head1->next, head2 == NULL ? NULL : head2->next, carry);
	pre->next = next;
	return pre;
}