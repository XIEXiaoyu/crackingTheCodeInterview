#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"
#include "4_1_2.h"


#ifndef _4_5_1_H_
#define _4_5_1_H_

/* 	The function InorderTraversal() traverses the tree, 
	and in the LDR manner.

	The second argument is a reference to a linked list. If
	the binary tree is a BST, then the list nodes are in a 
	desending order.
*/ 
void InorderTraversal(BtNode root, LinkedList* list);

#endif