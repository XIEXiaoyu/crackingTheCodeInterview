#include <stdio.h>
#include <stdlib.h>

//定义存放最小值的stack的每一个结点
struct MStack_ 
{
	int value;
	struct MStack_* next;
	int end;
};

typedef struct MStack_ * MStack;

//初始化存有最小值得stack
MStack MstackInit();

//压栈
MStack MPush(MStack stack, int value);
//出栈
MStack MPop(MStack stack, int* mData);