/*
注意： *present->top 和 (*present)->top 的不同。->结合优先级大于*
*/

#include <stdio.h>
#include <stdlib.h>

#include "3_4_1.h"


int main(int argc, char** argv)
{
	//产生三个stack
	Stack a = stack_ini(N);
	Stack b = stack_ini(N);
	Stack c = stack_ini(N);

	printf("Hanoi: %p, %p, %p\n", a, b, c);

	//将第一个stack里面存入5个数字，从大到小依次给进去。
	int array[] = {5, 4, 3, 2, 1};
	for(int i = 0; i < N; i++)
	{
		printf("Pushing (%d)...\n", array[i]);
		push_stack(a, array[i]);
	}

	hanoi(a, b, c, N);

	for(int i = 0; i < N; i++)
	{
		int * data = (int*)malloc(sizeof(int));
		pop(c, data);
		printf("%d\n", *data);
	}
	printf("\n");

	return 0;
	
}