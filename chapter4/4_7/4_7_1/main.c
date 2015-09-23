/*
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

#include "bst.h"
#include "4_7_1.h"

int main()
{
	BstNode root = createBst();

	BstNode bstNode1 = root->left->left->left->left;  //O
	BstNode bstNode2 = root->right->right->right->right;	  //I

	BstNode ancestor = GetFirstAncestor(root, bstNode1, bstNode2);
	printf("%d\n", ancestor->data);  //4

	return 0;
}