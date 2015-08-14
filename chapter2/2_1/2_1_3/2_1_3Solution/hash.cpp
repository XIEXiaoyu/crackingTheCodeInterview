#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

//using namespace std;

//c语言函数
Node nodeCreate(int number) {   //1.生成一个node
	Node node = (Node) malloc(sizeof(struct listNode));
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
	if(head == NULL) 
	{
		return NULL;
	}

	//2.删除了head
	else if(node == head)
	{
		if(node->next == NULL) //2.1 如果此时这个结点是唯一的一个结点
		{ 
			free(head);
			head = NULL;
		} 
		else  //2.2 如果整个list不只有head，还有其他的node	
		{		
			Node temp = head;
			head = head->next;
			free(temp);		
		}
		return head;
	}

	//3.删除了tail，此时tail不是唯一的一个结点
	else if(node->next == NULL) 
	{
		Node target = head->next;
		while(target->next != node) 
		{
			target = target->next;
		}
		target->next = NULL;
		free(node);
		return head;
	}

	//4.删除了不是head或者tail的结点
	else 
	{
		Node target = head;
		while(target->next != node) 
		{
			target = target->next;
		}
		target->next = node->next;
		free(node);
		return head;
	}
}
//end of C 语言函数

hash::hash()
{
	for(int i = 0; i < tableSize; i++) 
	{
		HashTable[i] = new item;
		HashTable[i]->value = -1;
		HashTable[i]->next = NULL;
	}
}

Node hash::AddItemAndReportDups(Node node)
{
	int value = node->num;
	int index = Hash(value);

	printf("3.The value is %d and the index is %d\n", value, index);

	if(HashTable[index]->value == -1) // 如果这个bucket是空的
	{
		HashTable[index]->value = value;
		printf("4.The HashTable[%d]'s value is %d\n", index, value);
		return NULL;
	}
	else  // bucket不是空的
	{
		item* Ptr = HashTable[index];

		while(Ptr->next != NULL && Ptr->value != value)
		{
			Ptr = Ptr->next;
		}

		if(Ptr->next == NULL)  //已经判断到这个bucket的最后一个元素了
		{
			if(Ptr->value != value) //不重复，那么加上去
			{
				item* n = new item;
				n->value = value;
				n->next = NULL;
				Ptr->next = n;
				return NULL;
			}
			else                    //重复，那么返回这个node
			{
				return node;
			}
			
		}
		else						//判断到中途，发现是重复的元素，也返回这个node
		{
			return node;            
		}		
	}
}

int hash::NumberOfItemsInIndex(int index) {
	item* Ptr = HashTable[index];
	int count = 0;
	if(Ptr->value == -1) 
	{
		return count;
	}
	else
	{	
		count++;
		while(Ptr->next != NULL) 
		{
			count++;
			Ptr = Ptr->next;
		}
		return count;
	}
}

// void hash::PrintTable() 
// {
// 	int number;
// 	for(int i = 0; i < tableSize; i++)
// 	{
// 		number = NumberOfItemsInIndex(i);
// 		std::cout << "--------------------------" << std::endl;
// 		std::cout << "the index is " << i << std::endl;
// 		std::cout << HashTable[i]->value << std::endl;
// 		std::cout << "# of items are " << number << std::endl;
// 		std::cout << "--------------------------" <<std::endl;
// 	}
// }

void hash::PrintItemsInIndex(int index) 
{
	item* Ptr;
	Ptr = HashTable[index];
	if(Ptr->value == -1) 
	{
		std::cout << "index = " << index << " is -1." << std::endl;
	}
	else
	{	
		std::cout << "index " << index << " contains the following items." << std::endl;
		while(Ptr != NULL) {
			std::cout << "-------------------" << std::endl;
			std::cout << Ptr->value << std::endl;
			std::cout << "-------------------" << std::endl;
			Ptr = Ptr->next;
		}
	}
}

// void hash::FindDrink(int value)
// {
// 	int index = Hash(value);
// 	bool foundValue = false;
// 	std::string drink;

// 	item* Ptr = HashTable[index];
// 	while(Ptr != NULL)
// 	{	
// 		if(Ptr->value == value)
// 		{
// 			foundValue = true;
// 			drink = Ptr->drink;
// 			break;
// 		}
// 		else
// 		{
// 			Ptr = Ptr->next;
// 		}
// 	}

// 	if(foundValue == true)
// 	{
// 		std::cout << "Favorite drink = " << drink << std::endl;
// 	}
// 	else
// 	{
// 		std::cout << value << "'s info was not found in the Hash Table.\n";
// 	}
// }

// void hash::RemoveItem(std::string value)
// {
// 	int index = Hash(value);

// 	item* delPtr;
// 	item* p1;
// 	item* p2;

// 	//case 0 - bucket is empty
// 	if(HashTable[index]->value == -1)
// 	{
// 		std::cout << value << "was not found in the Hash Table\n";
// 	}

// 	//case 1 - only 1 item contained in the bucket, and match
// 	else if(HashTable[index]->value == value && HashTable[index]->next == NULL)
// 	{
// 		HashTable[index]->value = -1;
// 		std::cout << value << " was removed from the Hash Table\n";
// 	}
// 	//case 2 - match is located in the first item in the bucket, but ther are more items in the bucket.
// 	else if(HashTable[index]->value == value)
// 	{
// 		delPtr = HashTable[index];
// 		HashTable[index] = HashTable[index]->next;
// 		delete delPtr;

// 		std::cout << value << " was removed from the Hash Table\n";
// 	}
// 	//case 3 - bucket contains items, but first item is not a match
// 	else
// 	{
// 		p2 = HashTable[index];
// 		p1 = p2->next;

// 		while(p1 != NULL && p1->value != value)
// 		{
// 			p2 = p1;
// 			p1 = p2->next;
// 		}

// 		//case 3.1 - no match
// 		if(p1 == NULL) 
// 		{
// 			std::cout << value << " was not found in the Hash Table\n";
// 		}
// 		//case 3.2 - match is found
// 		else
// 		{
// 			delPtr = p1;
// 			p1 = p1->next;
// 			p2->next = p1;

// 			delete delPtr;
// 			std::cout << value << " was removed from the Hash Table\n";
// 		}
// 	}	
// }

int hash::Hash(int key) //hash::Hash means the Hash() function comes from the hash class
{ 
	int index;

	index = key % tableSize;

	return index;
}


