//本题是解决3_2的进阶问题
#include <stdio.h>
#include <stdlib.h>

#include "3_3_2.h"

int main(int argc, char** argv)
{
	Sostacks sostacks = create();

	for(int i = 1; i <=32; i++)
	{
		sostacks = push(sostacks, i);
	}
	
	sostacks = selectStack(sostacks, -1, 1);


	return 0;
}