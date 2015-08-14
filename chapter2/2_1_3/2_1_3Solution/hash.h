#include <cstdlib>
#include <iostream>
#include <string>

//using namespace std;

//c语言函数
extern "C" {

	struct listNode {
		int num;
		struct listNode* next;
	};

	typedef struct listNode* Node;

	Node nodeCreate(int number);

	Node listAppend(Node head, int number);

	Node listSearch(Node head, int number);

	Node nodeDel(Node head, Node node);
}

#ifndef HASH_H
#define HASH_H

class hash{

private:
	static const int tableSize = 10;

	struct item{
		int value;
		item* next;
	};

	item* HashTable[tableSize];

public:
	hash();
	int Hash(int key);
	Node AddItemAndReportDups(Node node);
	int NumberOfItemsInIndex(int index);
	// void PrintTable();
	void PrintItemsInIndex(int index);
	// void FindDrink(int value);
	// void RemoveItem(int value);
};

#endif  /* HASH_H */