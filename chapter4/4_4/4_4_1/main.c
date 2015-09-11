#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"
#include "4_4_1.h"

int main(int argc, char* argv[])
{
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int len = LEGNTH(array);

	BstNode root = BuildBinaryTree(array, len);

	InorderTraversal(root);
	printf("\n");

	return 0;
}