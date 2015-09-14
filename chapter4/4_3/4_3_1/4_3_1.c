#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"
#include "4_3_1.h"

BstNode BuildBinaryTree(int array[], int len)
{
	if(len == 1 || len == 0)
	{
		if(len == 1)
		{
			BstNode root = CreateNode(array[0]);	
			return root;			
		}
		else
		{
			return NULL;
		}
	}
	
	int middleIndex = len / 2;

	BstNode root = CreateNode(array[middleIndex]);
	root->left = BuildBinaryTree(&array[0], middleIndex);
	if(len % 2 == 0)
	{
		root->right = BuildBinaryTree(&array[middleIndex+1], middleIndex-1);
	}
	else
	{
		root->right = BuildBinaryTree(&array[middleIndex+1], middleIndex);
	}
	
	return root;
}

void InorderTraversal(BstNode root)
{
	if(root == NULL)
	{
		return;
	}
	InorderTraversal(root->left);
	printf("%d ", root->data);
	InorderTraversal(root->right);
}

