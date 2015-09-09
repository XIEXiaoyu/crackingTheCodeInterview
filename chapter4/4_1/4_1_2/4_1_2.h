#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#ifndef __BT_H__
#define __BT_H__

struct BtNode_
{
	int data;
	struct BtNode_* left;
	struct BtNode_* right;
};

typedef struct BtNode_* BtNode;

BtNode NodeCreate(int data);

void InorderTraverse(BtNode root);

int ChooseMax(int left, int right);

int FindHeight(BtNode root);

// bool IsLeftRightHightBalanced(BtNode node);

bool IsBalancedTree(BtNode root);

#endif