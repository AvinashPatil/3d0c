#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define CHARS 26

struct trienode {
	bool isEnd;
	struct trienode *child[CHARS];
};

struct trienode * get_node() {
	struct trienode *node = (struct trienode *) malloc(sizeof(struct trienode));
	for(int i=0; i<CHARS; i++) {
		node->child[i] = NULL;
	}
	node->isEnd = false;
	return node;
}

void trie_insert(struct trienode **root, char *str) {
	if(*root == NULL) {
		*root = get_node();
	}
	if(str[0] != '\0') {
		// means there are still characters left
		trie_insert(&(*root)->child[str[0]-'a'], str+1);
	} else {
		(*root)->isEnd = true;
	}
}	

void printf_trie(struct trienode *root) {
	if(root) {
		for(int i=0; i<CHARS; i++) {
			if(root->child[i] != NULL) {
				printf("%c ", 'a' + i);
				printf_trie(root->child[i]);
			}
		}

		if(root->isEnd) {
			printf("\n");
		}
	}
}

void auto_complete(char *prefix, struct trienode *root) {
	
	for(int i=0; i<strlen(prefix); i++) {
		if(root->child[prefix[i] - 'a'] != NULL) {
			root = root->child[prefix[i] - 'a'];
		} else {
			printf("prefix does not match ");
			return;
		}
	}
	printf("%s + \n", prefix);
	printf_trie(root);	
}

void main() {
	struct trienode *root = NULL;
	trie_insert(&root, "hifi");
	trie_insert(&root, "hihello");
	trie_insert(&root, "hello");
	trie_insert(&root, "high");
	
	auto_complete("hi", root);
	//printf_trie(root);
}
