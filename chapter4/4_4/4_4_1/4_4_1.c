#include <stdio.h>
#include <stdlib.h>

#include "bst.h"
#include "list.h"
#include "queue.h"
#include "4_4_1.h"

List getLeveL0List(BstNode root)
{
	List list= createList();
	ListNode listNode = createListNode(root);
	insertList(&list, listNode);

	return list;
}

List getOutputList(List inputList)
{
	List outputList = createList();

	ListNode temp = inputList->head;
	while(temp != NULL)
	{
		BstNode bstNode = temp->data;
		if(bstNode->left != NULL)
		{
			ListNode listNode= createListNode(bstNode->left);
			insertList(&outputList, listNode);
		}
		if(bstNode->right != NULL)
		{
			ListNode listNode = createListNode(bstNode->right);
			insertList(&outputList, listNode);
		}
		temp = temp->next;
	}

	return outputList;
}

Queue getQueue(BstNode root)
{
	Queue queue = createQueue();

	//根据root,得到第一个链表，也是inputList
	List inputList = getLeveL0List(root);

	//把第一个链表插入到queue里面
	QueueNode queueNode = createQueueNode(inputList);
	enqueue(&queue, queueNode);

	//根据第一个链表，得到第二个链表
	List outputList = getOutputList(inputList);
	
	while(outputList->head != NULL)
	{
		queueNode = createQueueNode(outputList);
		enqueue(&queue, queueNode);
		outputList = getOutputList(outputList);
	}

	return queue;
}

List getListFromQueueNode(QueueNode queueNode)
{
	List list = queueNode->data;
	return list;
}

void printAllListBstFormat(Queue queue)
{
	QueueNode queueNode = (QueueNode)malloc(sizeof(struct QueueNode));
	List list = (List)malloc(sizeof(struct List));
	while(queue->head != NULL)
	{
		dequeue(&queue, &queueNode);
		list = getListFromQueueNode(queueNode);
		printBstList(list);
	}

	return;
}

void printAllListIntFormat(Queue queue)
{
	QueueNode queueNode = (QueueNode)malloc(sizeof(struct QueueNode));
	List list = (List)malloc(sizeof(struct List));
	while(queue->head != NULL)
	{
		dequeue(&queue, &queueNode);
		list = getListFromQueueNode(queueNode);
		printIntList(list);
	}

	return;
}

void printHappyList(BstNode root)
{
	Queue queue = getQueue(root);
	printAllListIntFormat(queue);
}