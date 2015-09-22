/*
	思路：	1. 	D,K,F, next is the father
			2.	Z,M,L, next is NULL
			3.  E,H,C, next is the right child
			4.  A,B, next is the most left node of his right child
	分析：	时间复杂度是
			空间复杂度也是


           A
         /	 \
    	B	  C
	   /\	 / \
	  D  E  F   G
	 	/ \      \
	   H   I      J
   	  / \          \
  	 K   L          M
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"
#include "4_6_2.h"

int main(int agrc, char* argv[])
{
	BstNode root = createBst();

	BstNode inputBstNode = root; //A 8
	inputBstNode = root->left; //B 2
	inputBstNode = root->right; //C 10;
	inputBstNode = root->left->left; //D 1
	inputBstNode = root->left->right; //E 6
	inputBstNode = root->right->left; //F 9
	inputBstNode = root->right->right; //G 11
	inputBstNode = root->left->right->left; //H 4
	inputBstNode = root->left->right->right; //I 7  NULL
	inputBstNode = root->right->right->right; //J 12
	inputBstNode = root->left->right->left->left; //K 3
	inputBstNode = root->left->right->left->right; //L 5 NULL
	inputBstNode = root->right->right->right->right; //M 13 NULL


	BstNode nextBstNode = findNextBstNode(root, inputBstNode);

	printf("%d\n", nextBstNode);


}
