#include <stdio.h>
#include <stdlib.h>

#ifndef __4_8_1_B_T_H__
#define __4_8_1_B_T_H__

#define CMAX 50

//struct bst node
struct BstNode
{
	char key; 
	struct BstNode* left;
	struct BstNode* right;
	struct BstNode* parent;
};

typedef struct BstNode* BstNode;

/*	create a BstNode 
	@argu	char data
	@retn 	BstNode 
*/
BstNode createBstNode(char key);

/* 	Create a binary tree root node.
	This function with appendChild() are used to create binary tree.
	@argument	char 	data
	@return		BstNode root
*/
BstNode createBtRoot(char data); //Bt is short for binary tree

/*	Append a left or a right child to a node. 
	This node could be a root node or a non root node.
	The 3rd argument indicates a left or a right child.
	The function returns the pointer of the appended the node
	@argument	BstNode appendedNode
	@argument	char 	data
	@argument	char 	ind  // indicator of 'l' or 'r'
	@return 	BstNode newNode
*/
BstNode appendChild(BstNode appendedNode, char data, char ind);

/*	create a fixed binary tree.
	@argu	void
	@retn	BstNode root
*/
BstNode createBst();

/*
	create a second fixed binary tree. 
*/
BstNode createBst1();

/*
	create a third bianry tree.
*/
BstNode createBst2();

/* 	Given a char, a char array and the index into the char is 
	going to be stored in the char array
	@argument 	char key
	@argument	char* string
	@argument	int index
	@return		int index 
*/
int insertCTA(char key, char* string, int index);	//CTA stands for "CharToArray"


/*	Inorder traverse bst
	@argu	BstNode root
	@retn 	void
*/
void printInorderTraverseBst(BstNode root);

/*	Inorder traverse bst, and store all the node in a char array.
	If the node is null, store it as char 'a'.
	@argument		BstNode root
	@argument		char* string
	@argument		int index
	@return 		int index
*/
int InorderTraverseBst(BstNode root, char* string, int index);




#endif