#include <stdio.h>
#include <stdlib.h>

#include "recordMin.h"

MStack MstackInit()
{
	MStack mstack = (MStack)malloc(sizeof(struct MStack_));
	mstack->next = NULL;
	mstack->end = -1;
	return mstack;
}

MStack MPush(MStack stack, int value)
{
	//如果stack只是初始化了，但是没有值
	if(stack->end == -1)
	{
		stack->end = 1; 
		stack->value = value;
		return stack;
	}
	else
	{
		MStack new = (MStack)malloc(sizeof(struct MStack_));
		new->value = value;
		new->end = 1;
		new->next = stack;
		return new;
	}
}

MStack MPop(MStack mstack, int* mData)
{
	//如果stack已经空了
	if(mstack->end == -1)
	{
		printf("It is an empty stack.\n");
	}
	else
	{
		*mData = mstack->value;
		MStack temp;
		//如果pop最后一个结点
		if(mstack->next == NULL)
		{
			mstack->end = -1;
		}
		//如果不是pop最后一个结点
		else
		{
			temp = mstack;
			mstack = mstack->next;
			free(temp);
		}						
	}
	return mstack;	
}




