#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"

BstNode CreateNode(int data)
{
	BstNode node = (BstNode)malloc(sizeof(struct BstNode));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

BstNode Insert(BstNode root, int data)
{
	if(root == NULL)
	{
		root = CreateNode(data);	
	}
	else if(data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}

	return root;
}

bool Search(BstNode root, int data)
{

	if(root == NULL)
	{
		return false;
	}

	if(root->data == data)
	{
		return true;
	}
	else if(data < root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}
}

BstNode FindMin(BstNode root)
{
	while(root->left != NULL)
	{
		root = root->left;
	}
	
	return root;
}


BstNode Delete(BstNode root, int data)
{
	if(root == NULL)
	{
		return NULL;
	}
	else if(data < root->data)
	{
		root->left = Delete(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = Delete(root->right, data);
	}
	else
	{
		//case 1: No child
		if(root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		//case 2: one child
		else if(root->left == NULL)
		{
			BstNode temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			BstNode temp = root;
			root = root->left;
			free(temp);	
		}
		//case 3: two children
		else 
		{
			BstNode temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}		
	}
	return root;
}