#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


int main() {

	LinkedList list = init_list();

	insert_node(&list, 1);
	printf("%p\n", list->head);
	insert_node(&list, 2);
	printf("%p\n", list->head);
	insert_node(&list, 3);
	printf("%p\n", list->head);

	Node target = listSearch(list, 3);
	printf("%p\n", target);

	bool isDelSuc = nodeDel(&list, target);
	if(isDelSuc == true)
	{
		printf("%d\n", list->head->num);
	}

	return 0;
}