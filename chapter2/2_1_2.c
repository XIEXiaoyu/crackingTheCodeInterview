//根据答案的提示，用两个指针来完成。
//时间复杂度是O(N);
//空间复杂度是O(1);

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

Node delDups(Node head) {
	Node current, runner, befRunner;
	current = head;
	befRunner = head;
	runner = head->next;
	while(current->next != NULL) {
		while(runner != NULL) {
			if(runner->num == current->num) {
				befRunner->next = runner->next;
				free(runner);
				runner= befRunner->next;
				
			} else {
				befRunner = befRunner->next;
				runner = runner->next;
			}
		}
		current = current->next;
		befRunner = current;
		runner = current->next;
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

	printf("3. Now we are testing the delDups() function.\n");
	head = delDups(head);
	item = head;
	while(item->next != NULL) {
		printf("%d ", item->num);
		item = item->next;
	}
	printf("%d\n\n\n\n", item->num);

	return 0;
}




