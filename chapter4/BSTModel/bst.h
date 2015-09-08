#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#ifndef _BST_H_
#define _BST_H_

struct BstNode 
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};

typedef struct BstNode* BstNode;

BstNode CreateNode(int data);

BstNode Insert(BstNode root, int data);

bool Search(BstNode root, int data);

BstNode FindMin(BstNode root);

BstNode Delete(BstNode root, int data);

#endif