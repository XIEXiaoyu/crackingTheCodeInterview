#include <stdio.h>
#include <stdlib.h>

#ifndef __4_4_1_BST_H__
#define __4_4_1_BST_H__

//bst node 结构体
struct BstNode
{
	int data;
	struct BstNode* left;
	struct BstNode* right;
};

typedef struct BstNode* BstNode;

//创建一个 bst node 
BstNode createBstNode(int data);

#endif