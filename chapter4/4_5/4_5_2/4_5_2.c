#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "list.h"
#include "4_1_2.h"
#include "4_5_2.h"

bool isBstUti(BtNode root, int min, int max)
{
	if(root == NULL)
	{
		return true;
	}

	if( (root->data > min && root->data <= max) &&
		isBstUti(root->left, min, root->data)  &&
		isBstUti(root->right, root->data, max)
	  )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isBst(BtNode root)
{
	return isBstUti(root, INT_MIN, INT_MAX);	
}
