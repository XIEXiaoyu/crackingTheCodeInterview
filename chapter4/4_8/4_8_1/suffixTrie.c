#include <stdio.h>
#include <stdlib.h>

#include "suffixTrie.h"
#include <string.h>

void addEndingToString(char* word)
{
	int i = 0;
	while(word[i] != '\0')
	{
		i++;
	}
	word[i] = '*';
	word[i+1] = '\0';
}

TrieNode createTrie(void)
{
	TrieNode root = (TrieNode)malloc(sizeof(struct TrieNode));
	memset(&(root->next), 0, sizeof(struct TrieNode*)*26);
	memset(&(root->key), 0, sizeof(char));

	return root;
}

TrieNode addCharacter(TrieNode inputNode, char key)
{
	int index = key - 'a';
	if((inputNode->next)[index] == '\0')
	{
		TrieNode newNode = (TrieNode)malloc(sizeof(struct TrieNode));
		(inputNode->next)[index] = newNode;
		newNode->key = key;
		return newNode;
	}
	else
	{
		return (inputNode->next)[index];
	}
}

void addEndChar(TrieNode inputNode, char key)
{
	TrieNode newNode = (TrieNode)malloc(sizeof(struct TrieNode));
	(inputNode->next)[26] = newNode;
	newNode->key = key;
}

void addWord(TrieNode root, char* word)
{
	addEndingToString(word);
	int i = 0;
	TrieNode temp = root;

	while(word[i] != '*')
	{
		temp = addCharacter(temp, word[i]);
		i++;
	}
	addEndChar(temp, '*');	
}






