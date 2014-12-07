/* Program to put all teh anagrams together

Learnings:

1. IN quick sort, do not increment M before. When the swap is required then only increment M. What if there were no swaps, you will wastefully swap in  the later stage.

2. Be mindful about string constants. Whenever we modify them copy them in a separate string. 

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>


void swap(char *word, int i, int j) {

	char temp;

	temp = word[i];
	word[i] = word[j];
	word[j] = temp;
}

void qsort1(char *word, int start, int end) {

	if(start < end) {

		int M = start;

		for(int i = start +1; i< end; i++) {
			if(word[i] < word[start]) {  // be careful about condition here.
				M = M + 1;   // always increment M when its required, so increment and then swap
				swap(word, i, M); // if we keep M already ahead then it will cause trouble in step after this for loop.
			}
		}

		swap(word, M, start);  // trouble here is there will be un necessary swap if M is 1 step ahead
		qsort1(word, start, M-1);
		qsort1(word, M+1, end);	
	}
}

#define CHARS 256

struct IndexNode{
	int index;
	struct IndexNode *next;
};
struct TrieNode{
	bool isEnd;
	struct TrieNode *child[CHARS];
	struct IndexNode *head;
};

struct TrieNode * newTrieNode() {
	struct TrieNode *node= (struct TrieNode *) malloc(sizeof(struct TrieNode ));
	node->isEnd = false;
	for(int i = 0; i<CHARS; i++) {
		node->child[i] = NULL;
	}
	node->head = NULL;
	return node;
}

struct IndexNode * newIndexNode(int index) {
	struct IndexNode *node= (struct IndexNode *) malloc(sizeof(struct IndexNode));
	node->index = index;
	node->next = NULL;
	return node;
}

void insert_str_trie(struct TrieNode **root, char *str, int index) {

	// Base case
	if (*root == NULL) {
		*root = newTrieNode();
	}
	
	if (*str != '\0') {
		// go deep unless end of the word by making nodes which is done in base case.	
		insert_str_trie(&(*root)->child[*str - 'a'], str+1, index);
	} else {
		// when we reach to the end of the word, there are two cases
		// already some word ends at the place : We have to just insert this word in the list.
		// Or we have reached first time here. Start a list.
		// Also, note that not all the lists will be at same level.
		// Some words may end between and some words may continue after this level as well. 
		// The list is simply of anagrams i.e. words having same characters and length as well.		
		if((*root)->isEnd) {
			struct IndexNode *pcrawl = (*root)->head;
			while(pcrawl->next)
				pcrawl = pcrawl->next;

			pcrawl->next = newIndexNode(index);

		} else {
			(*root)->head = newIndexNode(index);
			(*root)->isEnd = true;
		}
	}
}

void print_words(struct TrieNode *node, char **words) {
	struct IndexNode *temp = node->head;
	
	while(temp) {
		printf("%s ", words[temp->index]);
		temp = temp->next;
	}
		
}

void traverse_trie(struct TrieNode *root, char **words) {
	if(root != NULL) {
		for(int i=0; i <CHARS; i++) {
			if(root->child[i] != NULL) {
				if(root->child[i]->isEnd) {
					print_words(root->child[i], words);
				}
				traverse_trie(root->child[i], words);
			}
		}
	}
}

void printanagrams(char **words, int len) {
	struct TrieNode *root = NULL; 

	for(int i=0; i<len; i++) {
		char *str = (char *) malloc(strlen(words[i]) + 1);
		strcpy(str, words[i]);
		qsort1(str, 0 , strlen(str));
		insert_str_trie(&root, str, i);
	}

	traverse_trie(root, words);
	
}


void main() {
	char *words[] = {"cat", "dog", "tac", "god", "act", "gdo"};

	int len = sizeof(words) / sizeof(words[0]);
	printanagrams(words, len);
}

