#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "4_1_2.h"
#include "4_5_1.h"

void InorderTraversal(BtNode root, LinkedList* list)
{
	if(root == NULL)
	{
		return;
	}
	InorderTraversal(root->left, list);
	insert_node(list, root->data);
	InorderTraversal(root->right, list);
}

