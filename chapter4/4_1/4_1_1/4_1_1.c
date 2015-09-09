#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "4_1_1.h"

BtNode NodeCreate(int data)
{
	BtNode node = (BtNode)malloc(sizeof(struct BtNode_));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void InorderTraverse(BtNode root)  //LDR
{
	if(root == NULL)
	{
		return;
	}
	InorderTraverse(root->left);
	printf("%d\n", root->data);
	InorderTraverse(root->right);

	return;
}

int ChooseMax(int left, int right)
{
	int maximum = left >= right ? left : right;
	return maximum;
}

int FindHeight(BtNode root)
{
	int height;
	if(root == NULL){
		height = -1;
		return height;
	}

	printf("testing: node is %d\n", root->data);
	height = ChooseMax(FindHeight(root->left), FindHeight(root->right)) + 1;
	printf("testing: height is %d\n", height);
	return height;
}

// bool IsLeftRightHightBalanced(BtNode node)
// {
// 	int absoulute = abs(FindHeight(node->left) - FindHeight(node->right));
// 	if(absoulute <= 1)
// 	{
// 		return true;
// 	}
// 	return false;
// }

bool IsBalancedTree(BtNode root)
{
	if(root == NULL)
	{
		return true;
	}
	
	if(abs(FindHeight(root->left) - FindHeight(root->right)) > 1)
	{
		return false;
	}

	else
	{
		if(IsBalancedTree(root->left) && IsBalancedTree(root->right))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}