#include <stdio.h>
#include <stdlib.h>

#ifndef __4_4_1_LIST_H__
#define __4_4_1_LIST_H__

#include "bst.h"

//list node 结构体
struct ListNode 
{
	BstNode data;
	struct ListNode* next;
};

typedef struct ListNode* ListNode;

//list 结构体
struct List
{
	ListNode head;
	ListNode rear;
};	

typedef struct List* List;

/* 创建 list node 
   argu: BstNode 
   retn: ListNode
*/
ListNode createListNode(BstNode bstNode);

/* 创建 list
   argu: void
   retn: List;
*/
List createList(void);

/*	尾巴插入
	argu: List*
 	argu: ListNode
	retn: 通过List*
*/
void insertList(List* list, ListNode listNode);

/* 	打印list, 打印出的是BstNode
	argu: List
	retn: void
*/
void printBstList(List list);

/*
	打印list, 打印出的是BstNode的data, 是int
	@argu:	List
	@retn: 	void
*/
void printIntList(List list);


#endif