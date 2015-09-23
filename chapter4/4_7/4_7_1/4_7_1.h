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

#ifndef _4_7_1_H_
#define _4_7_1_H_

#include "bst.h"

/* 	Given two nodes, find their first ancestor
	@argu:	BstNode root
	@argu:	BstNode bstNode1
	@argu:	BstNode bstNode2
	@retn:	BstNode ancestor
*/
BstNode GetFirstAncestor(BstNode root, BstNode bstNode1, BstNode bstNode2);

#endif