#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst.h" 

#ifndef _4_4_1_H
#define _4_4_1_H

#define LEGNTH(s) (sizeof(s) / sizeof(int))

BstNode BuildBinaryTree(int array[], int len);

void InorderTraversal(BstNode root);

#endif