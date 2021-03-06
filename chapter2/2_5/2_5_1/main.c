#include <stdio.h>
#include <stdlib.h>

#include "delRevK.h"


int main() {
	Node head1 = nodeCreate(3);
	Node head2 = nodeCreate(3);

	int array1[] = {8,7,8,9,2};
	for(int i = 0; i < 2; i++) {
		head1 = listAppend(head1, array1[i]);
	}
	int array2[] = {4,5,3};
	for(int i = 0; i < 2; i++) {
		head2 = listAppend(head2, array2[i]);
	}

	printf("1.1 list 1 and the linked list is now:\n");

	Node item = head1;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	printf("1.2 list 2 and the linked list is now:\n");

	item = head2;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	Node head = addTwoLists(head1, head2);

	item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	return 0;
}