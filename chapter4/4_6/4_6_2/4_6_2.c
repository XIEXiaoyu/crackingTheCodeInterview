#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "4_6_2.h"

BstNode findNextBstNode(BstNode root, BstNode inputBstNode)
{
	BstNode nextBstNode = (BstNode)malloc(sizeof(struct BstNode));

	if(inputBstNode->left == NULL && inputBstNode->right == NULL)
	{
		if(inputBstNode->parent->left == inputBstNode)
		{
			nextBstNode = inputBstNode->parent;	
		}
		else
		{
			nextBstNode = NULL;
		}
	}

	else
	{
		bool isNoLeftdescendant = true;;

		BstNode temp = inputBstNode->right;

		while(temp != NULL)
		{
			if(temp->left == NULL)
			{
				temp = temp->right;
			}
			else
			{
				isNoLeftdescendant = false;
				break;
			}
		}

		if(isNoLeftdescendant == true)
		{
			nextBstNode = inputBstNode->right;	
		}
		else
		{
			while(temp->left != NULL)
			{
				temp = temp->left;
			}

			nextBstNode = temp;
		}

	}

	return nextBstNode;
}



