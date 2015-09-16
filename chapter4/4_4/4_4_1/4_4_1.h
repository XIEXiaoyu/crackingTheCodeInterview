#include <stdio.h>
#include <stdlib.h>

#ifndef __4_4_1_H__
#define __4_4_1_H__

#include "bst.h"
#include "list.h"
#include "queue.h"

/* give a root and generate a list
	@argu: 	BstNode root
	@List: 	List list
*/
List getLeveL0List(BstNode root);

/* give an input list then give out an output list
	@argu:	List
	@retn:	List
*/
List getOutputList(List inputList);

/*	give an tree root and then give out a queue
	@argu:	BstNode root
	@retn: 	Queue queue
*/
Queue getQueue(BstNode root);

/* 输入一个dequeue出来的元素，给出链表
	@argu: QueueNode queueNode
	@retn: List list 	
*/
List getListFromQueueNode(QueueNode queueNode);

/* 给一个Queue， 打印所有的list，list表现是BstNode
	@argu:	Queue queue
	@retn: 	void
*/
void printAllListBstFormat(Queue queue);

/* 给一个Queue， 打印所有的list，list表现是BstNode的data, 也就是int
	@argu:	Queue queue
	@retn: 	void
*/
void printAllListIntFormat(Queue queue);

/* 给一个bst, 打印所有的链表
	@argu: 	BstNode root
	@retn:	void
*/
void printHappyList(BstNode root);

#endif