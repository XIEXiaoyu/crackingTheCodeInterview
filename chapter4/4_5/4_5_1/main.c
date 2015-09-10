/*使用中序遍历*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "4_1_2.h"
#include "4_5_1.h"

int main(int argc, char* argv[])
{
	BtNode root  = NodeCreate(20);
	BtNode nodeB = NodeCreate(19);
	BtNode nodeC = NodeCreate(25);
	BtNode nodeD = NodeCreate(18);
	BtNode nodeE = NodeCreate(24);
	BtNode nodeF = NodeCreate(28);
	BtNode nodeG = NodeCreate(27);
	BtNode nodeH = NodeCreate(29);

	root->left   = nodeB;
	nodeB->left  = nodeD;
	root->right  = nodeC;
	nodeC->left  = nodeE;
	nodeC->right = nodeF;
	nodeF->left  = nodeG;
	nodeF->right = nodeH;

	LinkedList list = init_list();

	InorderTraversal(root, &list);

	while(list->head != NULL)
	{
		printf("%d ", list->head->num);
		list->head = list->head->next;
	}
	printf("\n");
}