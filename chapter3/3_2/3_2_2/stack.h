#include <stdio.h>
#include <stdlib.h>

#include "recordMin.h"

struct LSNode 
{
	int value;
	struct LSNode* next;
};

typedef struct LSNode* Node;

//制造堆栈，并且产生堆栈的第一个元素
Node LStackCreate(MStack mstack, int value);

//压栈
Node push(Node LSHead, int value, MStack * mstack);

//出栈
Node pop(Node LSHead, int* data, MStack* mstack, int** mData);

//求最小值
void getMin(MStack mstack, int* minimum);

//毁掉整个栈
void destroyLStack(Node LSHead);

