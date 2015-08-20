#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "2_6.h"

// 1. to find if there is a ring in the list
boP IsRingExistNFindMeetingPoint(Node head)
{
	boP isExited = (boP)malloc(sizeof(boP) * 1);
	isExited->isHaveRing = false;
	isExited->meetingPoint = NULL;

	Node fast = head, slow = head;
	while(fast->next != NULL || fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		printf("1.1 fast is %p\n", fast);
		printf("1.2 slow is %p\n\n", slow);
		if(fast == slow)
		{
			isExited->isHaveRing = true;
			isExited->meetingPoint = fast;

			return isExited;
		}		
	}

	return isExited;
}

// 2. to find the starting point of the ring
Node findRingHead(Node head)
{
	Node p1 = head;
	boP isExited = IsRingExistNFindMeetingPoint(head);

	_Bool isHaveRing = isExited->isHaveRing;
	if(isHaveRing == true)
	{
		Node p2 = isExited->meetingPoint;	
		while(p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		return p1;	
	}
	else
	{
		return NULL;
	}
}