/*
	current.left <= current.data < current.right
	自上而下传递最小值和最大值，逐渐将范围变窄
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "list.h"
#include "4_1_2.h"
#include "4_5_2.h"

int main(int argc, char* argv[])
{
	BtNode root  = NodeCreate(20);
	BtNode nodeB = NodeCreate(20);
	BtNode nodeC = NodeCreate(25);
	BtNode nodeD = NodeCreate(18);
	BtNode nodeE = NodeCreate(24);
	BtNode nodeF = NodeCreate(28);
	BtNode nodeG = NodeCreate(27);
	BtNode nodeH = NodeCreate(29);

	root->left   = nodeB;
	nodeB->left  = nodeD;
	root->right  = nodeC;
	nodeC->left  = nodeE;
	nodeC->right = nodeF;
	nodeF->left  = nodeG;
	nodeF->right = nodeH;

	if(isBst(root) == true)
	{
		printf("is BST\n");
	}
	else
	{
		printf("non bst\n");
	}

}