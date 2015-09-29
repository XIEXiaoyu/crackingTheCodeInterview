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
*/
/* 思路：给定一棵树，求出前序和中序，然后利用后缀树判断是否是子序列。
		要分析内容占用和时间花费，平均情况和最坏情况的意义。	
*/	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "suffixTrie.h"

int main()
{
	TrieNode root = createTrie();

	char arr[] = "bad";

	addWord(root, arr);

	printf("%c ", (root->next)[1]->key);
	printf("%c ", ((root->next)[1]->next)[0]->key);
	printf("%c ", (((root->next)[1]->next)[0]->next)[3]->key);
	printf("%c ", ((((root->next)[1]->next)[0]->next)[3]->next)[26]->key);
	printf("\n");




	return 0;
}  