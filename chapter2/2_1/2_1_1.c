//这道题我用一个单项非环的链表，里面的每一个数都是int类型。
//如果是环，那么就不能排序了。
//如果不是int,或者float,或者char,而是string的话，也不能排序。
//出于练习的目的，没有必要用双向链表
//重点：本题目前位置只完成了将一个列表用归并排序merge sorting,然后把sorting后的列表中的元素删除了，与题意不符合。


#include <stdio.h>
#include <stdlib.h>

//第一大部分：怎样构造链表
struct listNode {
	int num;
	struct listNode* next;
};

typedef struct listNode* Node;

Node nodeCreate(int number) {   //1.生成一个node
	Node node = malloc(sizeof(struct listNode));
	node->num = number;
	node->next = NULL;
	return node;	
} 

Node listAppend(Node head, int number) {  //2.向list的尾巴增加一个node
	Node node = nodeCreate(number);
	Node item = head;
	while(item->next != NULL) {
		item = item->next;
	}
	item->next = node;
	return head;
}

Node listSearch(Node head, int number) {  //3.寻找一个node
	Node target;
	Node item = head;
	while(item->num != number) {
		item = item->next;
	}
	target = item;
	return target;
}

Node nodeDel(Node head, Node node) { //4.删除一个node
	//1.如果head是空的
	if(head == NULL) {
		return NULL;
	}

	//2.删除了head
	else if(node == head) {
		//如果整个list只有一个head了 
		if(node->next == NULL){ //而且此时这个结点是唯一的一个结点
			head = NULL;
		} else{
		//如果整个list不只有head，还有其他的node	
			Node temp = head;
			head = head->next;
			free(temp);		
		}
		return head;
	}

	//3.删除了tail，而且tail不是唯一的一个结点
	else if(node->next == NULL) {
		Node target = head->next;
		while(target->next != node) {
			target = target->next;
		}
		target->next = NULL;
		free(node);
		return head;
	}

	//4.删除了不是head或者tail的结点
	else {
		Node target = head;
		while(target->next != node) {
			target = target->next;
		}
		target->next = node->next;
		free(node);
		return head;
	}
}

//第二大部分：怎样给链表排序
//1. 使用fast和slow指针找到链表的中间点
Node findMid(Node head) {
	if(head == NULL) {
		return NULL;
	}
	Node slow = head, fast = head;
	while(fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	return slow;
}

//2. 用归并排列merge sort 来排序
Node mergeSortedList(Node l1, Node l2) {
	Node head, tail;
	if(l1->num > l2->num) {
		head = l2;
		tail = l2;
		l2 = l2->next;
	} else {
		head = l1;
		tail = l1;
		l1 = l1->next;
	}

	while(l1 != NULL && l2 != NULL) {
		if(l1->num > l2->num) {
			tail->next = l2;
			tail = tail->next;
			l2 = l2->next;
		}
		else {    //l1 <= l2;
			tail->next = l1;
			tail = tail->next;
			l1 = l1->next;
		}
	}

	if(l1 != NULL) {
		tail->next = l1;
	}
	else {		
		tail->next = l2;
	}

	return head;
}

//3. 用递归来sort整个list
Node listSort(Node head) {
	Node sorted, l1, l2, item, tem;
	if(head->next == NULL) {
		return head;
	}
	else {
	//分半
	l1 = head;
	tem = findMid(head);
	l2 = tem->next;
	tem->next = NULL;
	//sort每半
	l1 = listSort(l1);
	l2 = listSort(l2);
	//merge两半
	sorted = mergeSortedList(l1,l2);	

	return sorted;
	}
}

//第三大部分，删除排序后的列表中重复的元素
Node removeDup(Node head) {
	Node item = head;
	Node aftItem = item->next;
	while(aftItem != NULL){
		if (aftItem->num == item->num){
			item->next = aftItem->next;
			free(aftItem);
			aftItem = item->next;			
		}
		else{
			aftItem = aftItem->next;
			item = item->next;
		}		
	}
	return head;
}

int main() {
	Node head = nodeCreate(1);
	printf("1. head is %d\n\n\n\n", head->num);

	printf("2. The list and the linked list is now:\n");
	int array[] = {4, 3, 2, 7, 2, 6, 5, 9, 5, 6, 0, 6, 11, 6};

	for(int i = 0; i < 14; i++) {
		head = listAppend(head, array[i]);
	}

	Node item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	printf("3. Now we are testing listSort() function.\n");
	Node sorted;
	sorted = listSort(head);
	printf("The list after sorting is:");
	item = sorted;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);	

	printf("4. Now we are testing deleting the duplicated element.\n");
	Node headFin = removeDup(sorted);
	item = headFin;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n", item->num);		

	return 0;
}




