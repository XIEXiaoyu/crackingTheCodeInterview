/*这回采用的方法是在不知道链表长度的条件下，使用两个指针，它们相距k,然后同时向后挪动这两个指针，
  当这后面的指针到走到链表末尾的时候，前面的指针所在的位置就是倒数第k个位置。
*/
#include <stdio.h>
#include <stdlib.h>

#include "delRevK.h"


int main() {
	Node head = nodeCreate(1);
	printf("1. head is %d\n\n\n\n", head->num);

	printf("2. The list and the linked list is now:\n");
	int array[] = {10, 3, 10, 7, 2, 11, 5, 9, 11, 6, 0, 6, 11, 6};

	for(int i = 0; i < 9; i++) {
		head = listAppend(head, array[i]);
	}

	Node item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	

	return 0;
}