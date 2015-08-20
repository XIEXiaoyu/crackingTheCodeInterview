//use fast and slow pointer to find the ring head
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "2_6.h"

int main() {
	Node head = nodeCreate(1);

	int array1[] = {2, 3, 4, 5, 6, 7, 8};
	for(int i = 0; i < 7; i++) {
		head = listAppend(head, array1[i]);
	}
	printf("the linked list is now:\n");

	Node item = head;
	while(item != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("\n\n");

	Node thirdNode = listSearch(head, 3);
	Node eighthNode = listSearch(head, 8);
	printf("the 3rd element is %d and its pointer is %p\n\n", 3, thirdNode);
	printf("the 8rd element is %d and its pointer is %p\n\n", 8, eighthNode);
	eighthNode->next = thirdNode;
	item = head;
	for(int j = 0; j < 17; j++)
	{
		printf("%d ", item->num);
		item = item->next; 
	}
	printf("\n\n");

	Node meetingPoint = findRingHead(head);
	if(meetingPoint == NULL)
	{
		printf("1.1 there is no ring in the list\n");
	}
	else
	{
		printf("1.2 the starting point is %p\n", meetingPoint);
	}

	return 0;
}