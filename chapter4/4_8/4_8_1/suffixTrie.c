#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "suffixTrie.h"


void addEndingToString(char* word, char* newWord)
{
	sprintf(newWord, "%s*", word);
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
	char newWord[80];
	addEndingToString(word, newWord);

	int i = 0;
	TrieNode temp = root;

	while(newWord[i] != '*')
	{
		temp = addCharacter(temp, newWord[i]);
		i++;
	}
	addEndChar(temp, '*');	
}

TrieNode searchChar(TrieNode node, char key)
{
	int index = key - 'a';
	if((node->next)[index] == NULL)
	{
		return NULL;
	}
	else
	{
		return (node->next)[index];
	}
}

// bool searchWord(TrieNode root, char* word)
// {
// 	char newWord[80];
// 	addEndingToString(word, newWord);

// 	TrieNode temp = root;
// 	int i = 0;
// 	while(newWord[i] != '*' && temp != NULL)
// 	{
// 		temp = searchChar(temp, newWord[i]);
// 		i++;
// 	}
// 	if(temp == NULL)
// 	{
// 		return false;
// 	}
// 	if((temp->next)[26] == NULL)
// 	{
// 		return false;
// 	}
// 	else
// 	{
// 		return true;
// 	}
// }

TrieNode createSuffixTrie(char* word)
{
	char newWord[80];
	addEndingToString(word, newWord);
	TrieNode root = createTrie();

	char* temp = newWord;
	
	while(temp[0] != '*')
	{
		//remove before flight
		int i = 0;
		while(temp[i] != '*')
		{
			printf("%c",temp[i]);
			i++;
		}
		printf("\n");

		addWord(root, temp);
		temp = &temp[1];
	}

	return root;
}

bool isSubstring(char* word, char* strTST)
{
	TrieNode root = createSuffixTrie(strTST);

	int index = word[0] - 'a';
	if( (root->next)[index] == NULL)
	{
		return false;
	}

	int i = 0;
	TrieNode temp = root;
	while(word[i] != '\0' && temp != NULL)
	{
		temp = searchChar(temp, word[i]);
		i++;
	}
	if(temp == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}