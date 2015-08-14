#include <cstdlib>
#include <iostream>
#include <string>

#include "hash.h"

//using namespace std;

int main(int argc, char** argv)
{
	Node head = nodeCreate(10);
	int array[] = {10, 3, 10, 7, 3, 11, 5, 9,11};
	for(int i = 0; i < 9; i++)
	{
		head = listAppend(head, array[i]);
	}

	printf("1.Now the originla list is:\n");
	Node temp = head;
	while(temp != NULL) 
	{
		printf("%d ", temp->num);
		temp = temp->next;
	}
	printf("\n");

	hash Hashy;
	Node temp1 = head, temp2, report;

	while(temp1 != NULL)
	{
		report = Hashy.AddItemAndReportDups(temp1);
		if(report == NULL) //如果没有重复
		{
			temp1 = temp1->next;
		}
		else
		{
			temp2 = report;
			head = nodeDel(head, report);
			temp1 = temp2->next;
		}
	}

	std::cout << "Now let's see the final linked list:\n";
	temp1 = head;
	while(temp1 != NULL)
	{
		std::cout << temp1->num << " ";
		temp1 = temp1->next;
	}

	std::cout << std::endl;

	return 0;
}