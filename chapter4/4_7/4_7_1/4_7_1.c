#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "4_7_1.h"

BstNode GetFirstAncestor(BstNode root, BstNode bstNode1, BstNode bstNode2)
{
	int len1 = GetDepth(root, bstNode1);
	int len2 = GetDepth(root, bstNode2);
	int len = len1>len2 ? len1-len2 : len2-len1;
	BstNode temp1 = len1>len2 ? bstNode1 : bstNode2;
	BstNode temp2 = len1>len2 ? bstNode2 : bstNode1;
	for(int i = 0; i < len; i++)
	{
		temp1 = temp1->parent;
	}

	while(temp1 != temp2)
	{
		temp1 = temp1->parent;
		temp2 = temp2->parent;
	}

	return temp1;
}