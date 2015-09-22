#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _4_6_2_H_
#define _4_6_2_H_

#include "bst.h"
/*	给任意一个BstNode, 找到它的下一个Node
	@argu	BstNode root
	@argu	BstNode inputBstNode
	@retn	BstNode nextBstNode
*/

BstNode findNextBstNode(BstNode root, BstNode inputBstNode);


#endif