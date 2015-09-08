#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h"

int main(int argc, char* argv[])
{
	BstNode root = NULL; //creating an empty tree

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);

	printf("pleae give an search input data.\n");
	int data;
	scanf("%d", &data);
	if(true == Search(root, data))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not found\n");
	}
	
	root = Delete(root, data);
	if(true == Search(root, data))
	{
		printf("Found\n");
	}
	else
	{
		printf("Not found\n");
	}

	return 0;
}