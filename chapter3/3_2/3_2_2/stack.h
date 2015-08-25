#include <stdio.h>
#include <stdlib.h>

struct LSNode 
{
	int value;
	struct LSNode* next;
};

typedef struct LSNode* Node;

//制造堆栈，并且产生堆栈的第一个元素
Node LStackCreate(int value);

//压栈
Node push(Node LSHead, int value);

//出栈
Node pop(Node LSHead, int* data);

//毁掉整个栈
void destroyLStack(Node LSHead);

