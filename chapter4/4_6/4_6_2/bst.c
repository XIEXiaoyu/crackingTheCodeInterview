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
	BstNode A = createBstNode(8);
	BstNode B = createBstNode(2);
	BstNode C = createBstNode(10);
	BstNode D = createBstNode(1);
	BstNode E = createBstNode(6);
	BstNode F = createBstNode(9);
	BstNode G = createBstNode(11);
	BstNode H = createBstNode(4);
	BstNode I = createBstNode(7);
	BstNode J = createBstNode(12);
	BstNode K = createBstNode(3);
	BstNode L = createBstNode(5);
	BstNode M = createBstNode(13);

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