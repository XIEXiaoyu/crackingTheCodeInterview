//这道题我用一个单项非环的链表，里面的每一个数都是int类型。
//如果是环，那么就不能排序了。
//如果不是int,或者float,或者char,而是string的话，也不能排序。
//出于练习的目的，没有必要用双向链表


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
	Node dummy = malloc
	, p1, p2;
	p1 = dummy; p2 = l2;
	dummy->next = l1;
	while(p1->next != NULL && p2!= NULL) {  //p1->next!= NULL 说明l1不是空的，用p1来记录不断变化的头指针，而l1是不变的（除非在第一次的时候把一个结点插在了它前面）
		if(p1->next->num >= p2->num) {
			p1->next = p2;
			p1 = p1->next;
			p2 = p2->next;
		}
		else {
			p1 = p1->next;
		}
	}

	return dummy->next;
}



int main() {
	Node head1 = nodeCreate(4);
	Node head2 = nodeCreate(2);
	printf("1. head is %d\n", head1->num);

	printf("2. number %d is appended to the list and the linked list is now:\n", 1);
	int array1[] = {3, 2, 5};
	int array2[] = {1, 6, 7};
	for(int i = 0; i < 3; i++) {
		head1 = listAppend(head1, array1[i]);
		head2 = listAppend(head2, array2[i]);
	}

	Node item = head1;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n", item->num);

	item = head2;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n", item->num);	

	// printf("3. After deleting the first node, the list now is: \n");
	// Node target = listSearch(head, 3);
	// head = nodeDel(head, target);

	// item = head;
	// while(item->next != NULL) {
	// 	printf("%d ", item->num);
	// 	item = item->next;
	// }
	// printf("%d\n", item->num);

	// printf("4. After deleting the last node, the list now is: \n");
	// target = listSearch(head, 2);
	// head = nodeDel(head, target);
	// item = head;
	// while(item->next != NULL) {
	// 	printf("%d ", item->num);
	// 	item = item->next;
	// }
	// printf("%d\n", item->num);	

	// printf("5. If a node in the middle is deleted, the list will be: \n");
	// target = listSearch(head,4);
	// head = nodeDel(head, target);
	// item = head;
	// while(item->next != NULL) {
	// 	printf("%d ", item->num);
	// 	item = item->next;
	// }
	// printf("%d\n", item->num);	

	// printf("5. Let's find the middle of the list.\n");
	// Node midPrior = findMid(head);
	// Node mid = midPrior->next;
	// printf("%d\n", middle->num);

	// Node leftHead = head;
	// midPrior->next = NULL;
	// Node rightHead = mid;

	printf("6. Now we are testing merge sorting.");
	head1 = mergeSortedList(head1, head2);
	printf("The sorted list is:\n");
	item = head1;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n", item->num);




	return 0;
}




