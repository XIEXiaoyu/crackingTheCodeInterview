#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "2_7.h"

Node getMiddle(Node head)
{
	Node fast = head, slow = head;
	while(fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

Node getHead2(Node middle)
{
	Node head2 = middle->next;
	return head2;
}

int getLength(Node head)
{
	Node item = head;
	int count = 0;
	while(item != NULL)
	{
		count++;
		item = item->next;
	}
	return count;
}

Node confirmHead1(Node head1, int length)
{
	if(length % 2 == 1)
	{
		Node temp = head1;
		head1 = head1->next;
		free(temp);
	}
	return head1;
}

revHT reverseFirstList(Node head1)
{
	revHT revht = (revHT)malloc(sizeof(revHT) * 1);

	if(head1->next == NULL)
	{
		revht->reverseTail = head1;
		revht->reverseHead = head1;
		return revht;
	}
	revht = reverseFirstList(head1->next);
	revht->reverseTail->next = head1;
	head1->next = NULL;
	revht->reverseTail = revht->reverseTail->next;
	return revht;
}

_Bool isPalindrome(Node head1, Node head2)
{
	_Bool isPalindrome = true;
	while(head1 != NULL)
	{
		if(head1->num != head2->num)
		{
			return false;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return isPalindrome;
}