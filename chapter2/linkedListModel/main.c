#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"


int main() {

	LinkedList list = init_list();

	insert_node_rear(&list, 1);
	printf("%p\n", list->rear);
	insert_node_rear(&list, 2);
	printf("%p\n", list->rear);
	insert_node_rear(&list, 3);
	printf("%p\n", list->rear);
	insert_node_rear(&list, 4);
	printf("%p\n", list->rear);
	insert_node_rear(&list, 5);
	printf("%p\n", list->rear);
	insert_node_rear(&list, 6);
	printf("%p\n", list->rear);


	Node target = listSearch(list, 2);
	printf("%p\n", target);

	bool isDel = nodeDel(&list, target);
	if(isDel == true)
	{
		Node temp = list->head;
		while(temp != NULL)
		{
			printf("%p\n", temp);
			temp = temp->next;
		}
	} 
	else
	{
		printf("del error.\n");
	}



	return 0;
}