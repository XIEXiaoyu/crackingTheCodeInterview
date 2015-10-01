#include <stdio.h>

#include "5_1.h"

int main()
{
	int m = 6;
	int n = 0x89;
	int j = 5, i = 3;

	printf("n is 			%x\n", n);

	int mask1 = ~((1 << (j+1)) - 1);
	printf("mask1 is 	 	%x\n", mask1);

	int mask2 = (1 << i) -1;
	printf("mask2 is 	 	%x\n", mask2);

	int maskforN = mask1 + mask2;
	printf("maskforN is   	%x\n", maskforN);

	int nPost = n & maskforN;
	printf("npost is 		%x\n", nPost);

	int mPost = m << i;
	printf("mPost is 		%x\n", mPost);

	int final = nPost + mPost;
	printf("final is 		%x\n", final); 
}