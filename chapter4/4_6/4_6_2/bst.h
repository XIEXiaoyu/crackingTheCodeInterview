#include <stdio.h>
#include <stdlib.h>

#ifndef _4_6_2_BST_H_
#define _4_6_2_BST_H_

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

/* 	Given a node, find its most left desendant of its right subtree
	@argu	BstNode node
	@retn 	BstNode leftMostNode
*/
BstNode getLeftMostNode(BstNode bstNode);

/* 	Given a node, find the ancestor that has been traversed in LDR
	@argu 	BstNode node
	@argu	BstNode root
	@retn	BstNode ancestorNonTraversed
*/
BstNode getAncestorNonTraversed(BstNode root, BstNode bstNode);

#endif


