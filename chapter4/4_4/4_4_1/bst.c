#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BstNode createBstNode(int data)
{
	BstNode bstNode = (BstNode)malloc(sizeof(struct BstNode));
	bstNode->data = data;
	bstNode->left = NULL;
	bstNode->right = NULL;

	return bstNode;
}

