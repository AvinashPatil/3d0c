#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define CHARS 26

struct listnode {
	char str[50];
	struct listnode *next;
};

struct trienode {
	bool isEnd;
	struct listnode *head;
	struct trienode *child[CHARS];
};

void add_node(struct trienode *root, char *str) {

	struct listnode *node = (struct listnode *) malloc(sizeof(struct listnode));
	strcpy(node->str, str);
	
	if(root->head == NULL) {
		root->head = node;
		node->next = NULL;
		return;
	}
	node->next = root->head;
	root->head = node;
	return;
}

struct trienode * getnode() {

	struct trienode *node = (struct trienode *) malloc(sizeof(struct trienode));
	node->isEnd = false;
	node->head = NULL;
	for(int i=0; i<CHARS; i++) {
		node->child[i] = NULL;
	}
	return node;
}

void insert_trie(char file[], char *str, struct trienode **root) {

	if(*root == NULL) {
		*root = getnode();
	}

	if(str[0] == '\0') {
		(*root)->isEnd = true;
		add_node(*root, file);
		return;
	} else {
		int index = str[0] - 'a';
		insert_trie(file, str+1, &(*root)->child[index]);
	}
	return;
}

void build_index(char file[], char *f[], int len, struct trienode **root) {

	for(int i=0; i<len; i++) {
		insert_trie(file, f[i], root);
	}
}

void printlist(struct listnode *head) {
	while(head) {
		printf("%s ", head->str);
		head = head->next;
	}
}

void query(struct trienode *root, char str[]) {
	if(str[0] == '\0' && root->isEnd == true) {
		//printf("found");
		printlist(root->head);
	} else {
		int index = str[0] - 'a';
		query(root->child[index], str+1);
	}
	return;
}


void main() {
	char *file1[] = {"the", "sky", "is", "blue"};
	char *file2[] = {"the", "apple", "is", "red"};
	char *file3[] = {"red", "label"};
	int l1 = sizeof(file1)/sizeof(file1[0]);
	int l2 = sizeof(file2)/sizeof(file2[0]);
	int l3 = sizeof(file3)/sizeof(file3[0]);
	struct trienode *root = NULL;
	build_index("file1", file1, l1, &root);
	build_index("file2", file2, l2, &root);
	build_index("file3", file3, l3, &root);
	//query(root, "the");
	query(root, "red");
}
