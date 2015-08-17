#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdbool.h>


#include "delRevK.h"


int main() {
	Node head = nodeCreate(1);
	printf("1. head is %d\n\n\n\n", head->num);

	printf("2. The list and the linked list is now:\n");
	int array[] = {10, 3, 10, 7, 2, 9, 5, 9, 11, 6, 0, 6, 11, 6};

	for(int i = 0; i < 9; i++) {
		head = listAppend(head, array[i]);
	}

	Node item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	Node target = listSearch(head, 11);

	_Bool isDel = NodeDelWithNoReturnValue(target);
	if(isDel == true) 
	{
		item = head;
		while(item->next != NULL) {
			printf("%d ", item->num);
			item = item->next;
		}
		printf("%d\n\n\n\n", item->num);		
	}
	else
	{
		printf("can not delete\n");
	}

	return 0;
}