/*
	This is an implementation of a standard trie. Give each input
	string a character '*' to mark its end, so to distinguish two
	wor hi and hit, for instance. String "hi" then would transfer 
	to "hi*" and "hit" would transfer to "hit*". 

	This is a simple trie that stores nothing. It is used for su-
	ffix trie later which is used to compare if a string is a su-
	bstring of another string.

	The functions are add and search.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef __4_8_1_SUFFIX_TRIE_H__
#define __4_8_1_SUFFIX_TRIE_H__

#define MAX 27

/* 	
	Define a struct for trie's node. Each node have an array of
	struct TridNode pointers, of which the size is 26 that repre-
	senting 26 English characters.

*/
struct TrieNode
{	
	char key;
	struct TrieNode* next[MAX]; //alphabetically	
};
typedef struct TrieNode* TrieNode;

/*
	Given a string, add a '*' to the end of the string.
	@argument	char*	word
	@argument	char*	newWord
	@return		void
*/
void addEndingToString(char* word, char* newWord);

/*
	create a trie
	@argument	void
	@return		TrieNode root;
*/
TrieNode createTrie(void);

/*
	Add a normal character to a node.
	@argument	TrieNode 	inputNode
	@argument	char 		key
	@return		TrieNode 	outputNode
*/
TrieNode addCharacter(TrieNode inputNode, char key);

/* 
	Add a '*' character to a node
	@argument	TridNode inputNode
	@argument	char key
	@return 	void
*/
void addEndChar(TrieNode inputNode, char key);

/*
	Add a word to the trie
	@argument	TrieNode* root
	@argument	char* word
	@return 	void
*/	

void addWord(TrieNode root, char* word);

/*
	Search a character to see if its in the Node
	@argument	TrieNode node
	@argument	char key
	@return 	TrieNode node
*/
TrieNode searchChar(TrieNode node, char key);

/*
	Search a word in the trie
	@argument	TrieNode root
	@argument	char* word
	@return 	bool true or false
*/
//bool searchWord(TrieNode root, char* word);

/*
	Given a word, create a suffix trie.
	@argument	char* word
	@return		TrieNode root
*/
TrieNode createSuffixTrie(char* word);

/*
	Given a word, check if it is a substring of another string.

	In this function, test if the first argument is the substring
	of the second argument.

	@argument	char* word
	@argument 	char* strTST(stringToSuffixTry)
	@return		bool true or false
*/
bool isSubstring(char* word, char* strTST);

#endif