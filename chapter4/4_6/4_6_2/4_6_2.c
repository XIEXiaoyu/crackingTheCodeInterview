#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "4_6_2.h"

BstNode findNextBstNode(BstNode root, BstNode inputBstNode)
{
	BstNode nextBstNode = (BstNode)malloc(sizeof(struct BstNode));

	// if current node has a right subtree
	if(inputBstNode->right != NULL)
	{
		nextBstNode = getLeftMostNode(inputBstNode);
	}


	else
	{
		//	If current node doesn't have a right subtree, but is the left child
		//	of a node. 
		if(inputBstNode->parent->left == inputBstNode)
		{
			nextBstNode = inputBstNode->parent;
		}

		//	If current node doesn't have a right subtree, but is the right 
		//  child of a node. 	
		else
		{
			nextBstNode = getAncestorNonTraversed(root, inputBstNode);
		}

	}

	return nextBstNode;
}



