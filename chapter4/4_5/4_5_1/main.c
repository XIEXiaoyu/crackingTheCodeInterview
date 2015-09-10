/*  使用中序遍历的方法。

	使用这种方法时，BST中不能含有重复的值。
	                20 
				 ／		、
				19 		25
			 ／	    、
			18	     19
	这棵树不是BST，遍历结果是 18 19 19 20 25，

					19
				 ／     、
				19		20
			 ／
			18

	这棵树是BST，遍历结果是 18 19 19 20。

	这两颗树的遍历结果是相同的，但是一棵树是BST，而一棵树不是，
	所以不能从遍历的结果盘点一个树是否是BST，当BST中含有重复的元素。
*/		

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