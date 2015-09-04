#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef _LINKED_LIST_MODEL_
#define _LINKED_LIST_MODEL_

struct listNode {
	int num;
	struct listNode* next;
};

typedef struct listNode* Node;

struct LinkedList
{
	Node head;
};

typedef struct LinkedList* LinkedList;

//初始化一个链表
LinkedList init_list();

//生成一个node
Node nodeCreate(int number);

//头插入法建立单链表
void insert_node(LinkedList* list, int number);

//寻找一个node
Node listSearch(LinkedList list, int number);

/*
	删除一个node
	1. 如果返回的是false,
		a) list是空的
		b) 给进的node为NULL，没有意义
		c) 给进的node不存在
	2. 如果返回的是true，说明删除成功了
*/
bool nodeDel(LinkedList* list, Node node);

#endif