//本方法是在已经链表有多长的条件下，倒数第k个，也就是正数第length－k 个。
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

	int count = FindQuantity(head);
	printf("3.The quantity is %d.\n", count);

	printf("4. We are now find the kth to last element.\n");
	//找倒数第K个结点，也就是正数第n-k个，index从0开始的话
	Node target = FindNodeByIndex(head, count-6);
	int num = target->num;
	printf("the kth to last number is %d\n", num);

	return 0;
}