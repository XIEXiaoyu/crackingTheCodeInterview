#include <stdio.h>
#include <stdlib.h>

#include "2_2_2.h"

//第一大部分：怎样构造链表

Nodum FindKthToLastNodeValueByIndex(Node head, int index)
{
	Nodum target = (Nodum)malloc(sizeof(Nodum) * 1);
	target->node = NULL;
	target->num = 1;
	Node temp;

	if(head == NULL)
	{
		return target;
	}
	else
	{
		target = FindKthToLastNodeValueByIndex(head->next, index);
		if(target->num == index)
		{
			target->node = head;
			target->num = target->num + 1;
			return target;

		}
		else
		{
			target->num = target->num + 1;
			return target;
		}
	}
}