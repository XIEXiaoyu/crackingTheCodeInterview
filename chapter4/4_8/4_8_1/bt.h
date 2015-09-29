#include <stdio.h>
#include <stdlib.h>

#ifndef __4_8_1_B_T_H__
#define __4_8_1_B_T_H__

//struct bst node
struct BstNode
{
	int data; 
	struct BstNode* left;
	struct BstNode* right;
	struct BstNode* parent;
};

typedef struct BstNode* BstNode;

/*	create a BstNode 
	@argu	int data
	@retn 	BstNode 
*/
BstNode createBstNode(int data);

/*	create a bst
	@argu	void
	@retn	BstNode root
*/
BstNode createBst();

/*	Inorder traverse bst
	@argu	BstNode root
	@retn 	void
	functionality: print the bst, and it will be in the accending order
*/
void InorderTraverseBst(BstNode root);



#endif