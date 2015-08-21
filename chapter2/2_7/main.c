/*
1.Firstly, use fast and slow pointers to seperate the list into two sublists,
  Secondly, reverse the first list
  Lastly, compare the two strings.
  
2.fast-slow pointer to seperate the list

3.at least 5 methods to reverse the first list:
 http://blog.csdn.net/feliciafay/article/details/6841115
 http://blog.csdn.net/wuxinliulei/article/details/22730041

4.I use the recursive method to reverse the list
*/
#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "2_7.h"

int main() {
	Node head = nodeCreate(1);
	int array[] = {2};
	// int array[] = {2, 3, 4, 5, 6, 5, 4, 3, 2, 1};
	for(int i =0; i < 1; i++)
	{
		head = listAppend(head, array[i]);
	}

	int length = getLength(head);

	Node middle = getMiddle(head);

	Node head2 = getHead2(middle);

	middle->next = NULL;

	revHT revht = reverseFirstList(head);

	Node revhead1 = revht->reverseHead;

	Node head1 = confirmHead1(revhead1, length);

	_Bool isP = isPalindrome(head1, head2);
	if(isP == true)
	{
		printf("palindrome\n");
	}
	else
	{
		printf("not palindrome\n");
	}

	return 0;
}