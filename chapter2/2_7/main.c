/*
1.To solve the problem, we firstly use fast and slow pointers to seperate the list into two sublists,
  then, we reverse the first list. Lastly, we compare the two strings.
  1)the methof of fast-slow pointer to find the starting point of the second list need N computation.
2.To find the starting point of the second list, we could use another method other than fast slow.
  1)count how long the list is: need N computation
  2)find the starting point of the second list: need N/2 computation.
3.To reverse the first list, we have at least 5 methods.
  reference: http://blog.csdn.net/feliciafay/article/details/6841115, has 4 methods.
  			 http://blog.csdn.net/wuxinliulei/article/details/22730041, has 1 method.

4.I am gonna us fast and slow and do 4 methods listed in http://blog.csdn.net/feliciafay/article/details/6841115
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