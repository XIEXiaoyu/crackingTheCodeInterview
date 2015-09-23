#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BstNode createBstNode(int data)
{
	BstNode bstNode = (BstNode)malloc(sizeof(struct BstNode));
	bstNode->data = data;
	bstNode->left = bstNode->right = bstNode->parent = NULL;

	return bstNode;
}

//create a bst
BstNode createBst()
{
	BstNode A = createBstNode(10);
	BstNode B = createBstNode(4);
	BstNode C = createBstNode(12);
	BstNode D = createBstNode(3);
	BstNode E = createBstNode(8);
	BstNode F = createBstNode(11);
	BstNode G = createBstNode(13);
	BstNode N = createBstNode(2); //new element
	BstNode H = createBstNode(6);
	BstNode I = createBstNode(9);
	BstNode J = createBstNode(14);
	BstNode O = createBstNode(1); //new element
	BstNode K = createBstNode(5);
	BstNode L = createBstNode(7);
	BstNode M = createBstNode(15);
	
	A->left  = B;
	A->right = C;

	B->left  = D;
	B->right = E;
	
	E->left  = H;
	E->right = I;
	
	H->left  = K;
	H->right = L;
	
	C->left  = F;
	C->right = G;
	
	G->right = J;
	
	J->right = M;

	D->left = N; //new element

	N->left = O; //new element

	B->parent = A;
	C->parent = A;
	D->parent = B;
	E->parent = B;
	F->parent = C;
	G->parent = C;
	H->parent = E;
	I->parent = E;
	J->parent = G;
	K->parent = H;
	L->parent = H;
	M->parent = J;
	N->parent = D; //new element
	O->parent = N; //new element

	return A;
}

void InorderTraverseBst(BstNode root)
{
	if(root == NULL)
	{
		return;
	}
	if(root->left != NULL)
	{
		InorderTraverseBst(root->left);
	}
	printf("%d ", root->data);
	if(root->right != NULL)
	{
		InorderTraverseBst(root->right);
	}
	
	return;
}

BstNode getLeftMostNode(BstNode bstNode)
{
	BstNode temp = bstNode->right;

	while(temp->left != NULL)
	{
		temp = temp->left;
	}

	return temp;
}

BstNode getAncestorNonTraversed(BstNode root, BstNode bstNode)
{
	BstNode temp = bstNode->parent;

	while(temp->parent->right == temp && temp->parent != root)
	{
		temp = temp->parent;
	}

	if(temp->parent == root)
	{
		return NULL;
	}
	return temp->parent;
}

int GetDepth(BstNode root, BstNode node)
{
	BstNode temp = node;
	int length = 0;
	while(temp->parent != NULL)  
	{		
		temp = temp->parent;
		length++;
	}

	return length;
}





