#include <stdio.h>
#include <stdlib.h>

//定义一个栈，是个顺序栈，栈结构体里面包含一个指向同类结构体的指针
struct SOStacks  //SOStacks is short or setOfStacks
{
	int a[10];
	int top;
	int quota;
	struct SOStacks * pre;
	struct SOStacks * next;
};
typedef struct SOStacks* Sostacks;

//初始化这个大栈
Sostacks create();

//压栈
Sostacks push(Sostacks sostacks, int value);

//出栈
Sostacks pop(Sostacks sostacks, int* data);

//找到指定的stack
Sostacks selectStack(Sostacks presentStack, int direction, int index);



