#include <stdio.h>
#include <stdlib.h>

#include "3_3_1.h"

int main(int argc, char** argv)
{
	Sostacks sostacks = create();
	printf("1. top is %d\n\n", sostacks->top);

	for(int i = 1; i <=12; i++)
	{
		sostacks = push(sostacks, i);
		// printf("top is %d\n", sostacks->top);
		// printf("sostacks->a[top-1] is %d\n\n", sostacks->a[sostacks->top-1]);
	}

	int* data =(int*)malloc(sizeof(int));
	for(int j = 1; j <=13; j++){
		sostacks = pop(sostacks, data);
		printf("data is %d\n\n", *data);		
	}

	return 0;
}