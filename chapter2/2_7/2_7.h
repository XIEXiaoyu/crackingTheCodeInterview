#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#include "list.h"

struct reverseHeadTail
{
	Node reverseHead;
	Node reverseTail;
};
typedef struct reverseHeadTail* revHT;

Node getMiddle(Node head);
Node getHead2(Node middle);
revHT reverseFirstList(Node head1);
int getLength(Node head);
Node confirmHead1(Node head1, int length);
_Bool isPalindrome(Node head1, Node head2);
