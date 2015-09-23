/*
	思路：	Using LDR, if I choose a node as current, then its next should be
			its left most descendant of his right subtree. For example, for 
			node A, B, C, E, G, H and J the next node is the right child F, K, 
			G, I, J, L and M seperately.

			But what if the current node has no right child, for example, nodes
			D, F, I, K, L, M, N and O. We need to find its father. For node D, F,
			K, N and O, we could find its father easily and they are B, C, H, D
			and N. But for I and L, we need to find the node the that has been
			traversed, that is A and E. 

			For node M, it is special, as there is no next node of it.
		
		           A     					    
		         /	 \
		    	B	  C
			   /\	 / \
			  D  E  F   G
			 /	/ \      \
			N  H   I      J
		   /  / \          \
		  O	 K   L          M
		           10                              
		         /	 \
		    	4	  12
			   /\	 / \
			  3  8  11  13
			 /	/ \      \
			2  6   9      14
		   /  / \          \
		  1	 5   7          15		  
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"
#include "4_6_2.h"

int main(int agrc, char* argv[])
{
	BstNode root = createBst();

	InorderTraverseBst(root);
	printf("\n");

	BstNode inputBstNode = root; //A 10
	inputBstNode = root->left; //B 4
	inputBstNode = root->right; //C 12;
	inputBstNode = root->left->left; //D 3
	inputBstNode = root->left->right; //E 8
	inputBstNode = root->right->left; //F 11
	inputBstNode = root->right->right; //G 13
	inputBstNode = root->left->right->left; //H 6
	inputBstNode = root->left->right->right; //I 9  
	inputBstNode = root->right->right->right; //J 14
	inputBstNode = root->left->right->left->left; //K 5
	inputBstNode = root->left->right->left->right; //L 7
	inputBstNode = root->right->right->right->right; //M 15 NULL
	inputBstNode = root->left->left->left; //N new 2
	inputBstNode = root->left->left->left->left; //O new 1

	BstNode nextBstNode = findNextBstNode(root, inputBstNode);
	printf("%d\n", nextBstNode->data);
}
