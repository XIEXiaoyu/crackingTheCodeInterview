#include <stdio.h>
#include <stdlib.h>

#include "2_2_2.h"

int main() {
	Node head = nodeCreate(10);

	printf("2. The list and the linked list is now:\n");
	int array[] = {9,8,7,6,5,4,3,2,1};

	for(int i = 0; i < 9; i++) {
		head = listAppend(head, array[i]);
	}

	Node item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	Nodum nodum = FindKthToLastNodeValueByIndex(head, 10);
	printf("%d\n", nodum->node->num);
}