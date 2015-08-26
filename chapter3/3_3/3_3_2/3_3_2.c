#include <stdio.h>
#include <stdlib.h>

#include "3_3_2.h"

Sostacks create()
{
	Sostacks sostacks = (Sostacks)malloc(sizeof(struct SOStacks));
	printf("5. head is %p\n", sostacks);
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

Sostacks selectStack(Sostacks presentStack, int direction, int index)
{
	/*找到相对于目前的stack的第index个stack，
	  如果direction给－1，代表向前找，
	  如果direction给＋1，代表向后找。
	  例如：direction＝1， index＝1，表示从当前stack向后的第一个stack。
	*/
	int i = 1; 
	Sostacks selectedstack = presentStack;

	if(direction == 1)
	{
		while(i <= index && selectedstack != NULL)
		{
			selectedstack = selectedstack->next;
			i++;
		}
		if(selectedstack == NULL)
		{
			printf("the index is beyond the limit.\n");
			return selectedstack;
		}

		return selectedstack;
	}

	//当direction == －1；
	else
	{
		while( i <= index && selectedstack!= NULL)
		{
			selectedstack = selectedstack->pre;
			i++;
		}
		if(selectedstack == NULL)
		{
			printf("the index is beyond the limit.\n");
			return selectedstack;
		}

		return selectedstack;
	}
}

Sostacks leftShiftOneStack(Sostacks stack)
{
	Sostacks nextStack = stack->next;
	if(nextStack == NULL)
	{
		for(int i = 0; i < stack->top-1; i++)
		{
			stack->a[i] = stack->a[i+1];
		}
		stack->top--;
	}
	else
	{
		stack->a[stack->top-1] = nextStack->a[0];

		for(int i = 0; i < nextStack->top-1; i++)
		{
			nextStack->a[i] = nextStack->a[i+1];
		}
	}

	return stack;
}

Sostacks leftShiftSetOfStacks(Sostacks presentStack)
{
	Sostacks item = presentStack;
	while(item != NULL)
	{
		item = leftShiftOneStack(item);
		item = item->next;
	}

	return presentStack;
}

Sostacks popAt(Sostacks presentStack, int* Adata)
{
	//如果当前stack是空的
	if(presentStack->pre == NULL && presentStack->top == 0)
	{
		printf("The setOfStacks is empty.\n");
		return NULL;
	}

	*Adata = presentStack->a[presentStack->top-1];
	//进行左移动
	presentStack = leftShiftSetOfStacks(presentStack);
	return presentStack;
}

