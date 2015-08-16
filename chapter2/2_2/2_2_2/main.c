/*这回采用的方法是在不知道链表长度的条件下，使用两个指针，它们相距k,然后同时向后挪动这两个指针，
  当这后面的指针到走到链表末尾的时候，前面的指针所在的位置就是倒数第k个位置。
*/
#include <stdio.h>
#include <stdlib.h>

#include "delRevK.h"


int main() {
	Node head = nodeCreate(1);

	printf("2. The list and the linked list is now:\n");
	int array[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

	for(int i = 0; i < 9; i++) {
		head = listAppend(head, array[i]);
	}

	Node item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		printf("%p\n", item);
		item = item->next;
	}
	printf("%d ", item->num);
	printf("%p\n\n", item);

	int index = 10;
	Nodum target = FindKthToLastNodeValueByIndex(head,index);
	printf("3. The %dth to last is %d\n", index, target->node->num);
	
	return 0;
}