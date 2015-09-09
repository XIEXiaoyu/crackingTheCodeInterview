#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "4_1_1.h"

int main(int argc, char* argv[])
{

	BtNode root  = NodeCreate(1);
	BtNode node2 = NodeCreate(2);
	BtNode node3 = NodeCreate(3);
	BtNode node4 = NodeCreate(4);
	BtNode node5 = NodeCreate(5);
	BtNode node6 = NodeCreate(6);
	BtNode node7 = NodeCreate(7);
	BtNode node8 = NodeCreate(8);
	BtNode node9 = NodeCreate(9);

	root->left   = node2;
	root->right  = node3;

	node2->left  = node4;
	node2->right = node5;

	node5->left = node7;
	node5->right = node8;

	node8->right = node9;

	node3->right = node6;

	int height = FindHeight(node5);
	printf("height is %d\n", height);

	if(IsBalancedTree(node2) == true)
	{
		printf("bal\n");
	}
	else
	{
		printf("nonbal\n");
	}

	return 0;
}