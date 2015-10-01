/*
		           A     					    
		         /	 \
		    	B	  C
			   /\	 / \
			  D  E  F   G
			 /	/ \      \
			N  H   I      J
		   /  / \          \
		  O	 K   L          M
		           10                              
		         /	 \
		    	4	  12
			   /\	 / \
			  3  8  11  13
			 /	/ \      \
			2  6   9      14
		   /  / \          \
		  1	 5   7          15	

		  		  	  c
			   		 / \
			  	    f  	g
			 	         \
			              j
		                   \
		   		          	m	

			  	 e  
			 	/ \      
			   h   i      
		      / \          
		   	 k   l          
*/
/* 思路：给定一棵树，求出前序和中序，然后利用后缀树判断是否是子序列。
		要分析内容占用和时间花费，平均情况和最坏情况的意义。	
*/	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "suffixTrie.h"
#include "bt.h"

int main()
{
	BstNode root 	= createBst();
	BstNode root1 	= createBst1();
	BstNode root2 	= createBst2();

	char string[CMAX];
	char string1[CMAX];
	char string2[CMAX];

	int index 	= InorderTraverseBst(root, string, 0);
	int index1 	= InorderTraverseBst(root1, string1, 0);
	int index2 	= InorderTraverseBst(root2, string2, 0);

	printf("string is %s\n", string);
	printf("string1 is %s\n", string1);
	printf("string2 is %s\n", string2);

	if(isSubstring(string1, string) == true)
	{
		printf("1 Yes\n");
	}

	if(isSubstring(string2, string) == true)
	{
		printf("2 Yes\n");
	}

	char string3[] = "abcdef";
	if(isSubstring(string3, string) == true)
	{
		printf("3 Yes\n");
	}
	else
	{
		printf("3 No.\n");
	}

	//Remove before flight. 
	//These code are used to test functions of createBtRoot() and appendChild()
	BstNode createBtRoot(char data);
	BstNode appendChild(BstNode appendedNode, char data, char ind);

	BstNode H = createBtRoot('h');
	BstNode K = appendChild(H, 'k', 'l');
	BstNode L = appendChild(H, 'p', 'r');

	char string4[CMAX];
	int index4 	= InorderTraverseBst(H, string4, 0);
	if(isSubstring(string4, string) == true)
	{
		printf("4 Yes\n");
	}
	else
	{
		printf("4 No.\n");
	}


	return 0;
}  	