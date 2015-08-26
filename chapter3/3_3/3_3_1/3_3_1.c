#include <stdio.h>
#include <stdlib.h>

#include "3_3_1.h"

Sostacks create()
{
	Sostacks sostacks = (Sostacks)malloc(sizeof(struct SOStacks));
	sostacks->top = 0;
	sostacks->quota = 10;
	sostacks->pre = NULL;
	sostacks->next = NULL;

	return sostacks;
} 

Sostacks push(Sostacks sostacks, int value)
{
	//如果当前的stack满了
	if(sostacks->top == sostacks->quota)
	{
		Sostacks new_sostacks = create();
		new_sostacks->top++;
		new_sostacks->pre = sostacks;
		sostacks->next = new_sostacks;
		new_sostacks->next = NULL;
		new_sostacks->a[new_sostacks->top-1] = value;
		return new_sostacks;
	}

	//如果当前stack还没有满
	else
	{
		sostacks->top++;
		sostacks->a[sostacks->top-1] = value;
		return sostacks;
	}
}

Sostacks pop(Sostacks sostacks, int* data)
{
	//如果只剩下一个stack了。
	if(sostacks->pre == NULL)
	{
		//这个setOfStacks已经空了，告知没有元素了。
		if(sostacks->top == 0)
		{
			printf("The whole setOfStacks is empty.\n");
			return NULL;
		}

		//这个stack还有其他元素。
		else
		{
			*data = sostacks->a[sostacks->top-1];
			sostacks->top--;
			return sostacks;
		}
	}

	//如果有至少一个stack
	else
	{
		*data = sostacks->a[sostacks->top-1];
		sostacks->top--;

		//如果pop之后，当前stack空了
		if(sostacks->top == 0)
		{
			Sostacks temp;
			temp = sostacks;
			sostacks = sostacks->pre;
			sostacks->next = NULL;
			free(temp);
		}

		//如果pop之后，当前stack还有元素，正常返回。
		return sostacks;
	}
}

