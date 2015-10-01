#include <stdio.h>
#include <stdlib.h>

#include "bt.h"

BstNode createBstNode(char key)
{
	BstNode bstNode = (BstNode)malloc(sizeof(struct BstNode));
	bstNode->key = key;
	bstNode->left = NULL;
	bstNode->right = NULL;
	bstNode->parent = NULL;

	return bstNode;
}

BstNode createBtRoot(char data){
	BstNode root = createBstNode(data);

	return root;
}

/*	Append a left or a right child to a node. 
	This node could be a root node or a non root node.
	The 3rd argument indicates a left or a right child.
	The function returns the pointer of the appended the node
	@argument	BstNode appendedNode
	@argument	char 	data
	@argument	char 	ind  // indicator of 'l' or 'r'
	@return 	BstNode appendingNode
*/
BstNode appendChild(BstNode appendedNode, char data, char ind)
{
	BstNode appendingNode = createBstNode(data);
	if(ind == 'l')
	{
		appendedNode->left = appendingNode;
	}
	else
	{
		appendedNode->right = appendingNode;
	}

	return appendingNode;
}

//create a bst
BstNode createBst()
{
	BstNode A = createBstNode('a');
	BstNode B = createBstNode('b');
	BstNode C = createBstNode('c');
	BstNode D = createBstNode('d');
	BstNode E = createBstNode('e');
	BstNode F = createBstNode('f');
	BstNode G = createBstNode('g');
	BstNode N = createBstNode('n'); //new element
	BstNode H = createBstNode('h');
	BstNode I = createBstNode('i');
	BstNode J = createBstNode('j');
	BstNode O = createBstNode('o'); //new element
	BstNode K = createBstNode('k');
	BstNode L = createBstNode('l');
	BstNode M = createBstNode('m');
	
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

BstNode createBst1()
{
	BstNode C = createBstNode('c');
	BstNode F = createBstNode('f');
	BstNode G = createBstNode('g');
	BstNode J = createBstNode('j');
	BstNode M = createBstNode('m');

	C->left = F;
	C->right = G;
	G->right = J;
	J->right = M;

	return C;
}

BstNode createBst2()
{
	BstNode E = createBstNode('e');
	BstNode H = createBstNode('h');
	BstNode I = createBstNode('i');
	BstNode K = createBstNode('k');
	BstNode L = createBstNode('l');

	E->left = H;
	E->right = I;
	H->left = K;
	H->right = L;

	return E;
}

int insertCTA(char key, char* string, int index)	//CTA stands for "CharToArray"
{
	string[index] = key;
	return index+1;
}

void printInorderTraverseBst(BstNode root)
{
	if(root == NULL)
	{
		return;
	}
	printInorderTraverseBst(root->left);

	printf("%c ", root->key);

	printInorderTraverseBst(root->right);
	
	return;
}

int InorderTraverseBst(BstNode root, char* string, int index)
{
	if(root == NULL)
	{
		index = insertCTA('a', string, index);
		return index;
	}

	index = InorderTraverseBst(root->left, string, index);

	index = insertCTA(root->key, string, index);

	index = InorderTraverseBst(root->right, string, index);
	
	return index;
}

