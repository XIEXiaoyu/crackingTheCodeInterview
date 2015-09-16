#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

BstNode createTree(void)
{
	BstNode root 	 = createBstNode(1);
	BstNode bstNode2 = createBstNode(2);
	BstNode bstNode3 = createBstNode(3);
	BstNode bstNode4 = createBstNode(4);
	BstNode bstNode5 = createBstNode(5);
	BstNode bstNode6 = createBstNode(6);
	BstNode bstNode7 = createBstNode(7);

	root->left 	= bstNode2;
	root->right = bstNode3;

	bstNode2->left 	= bstNode4;
	bstNode2->right = bstNode5;

	bstNode3->left  = bstNode6;
	bstNode3->right = bstNode7;

	return root;
}