#include<stdio.h>
#include<stdlib.h>

struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
	
};

struct listnode {
	int sum;
	struct listnode *prev;
	struct listnode *next;
};

struct treenode *getnode(int i) {
	struct treenode *node = (struct treenode *)malloc(sizeof(struct treenode));
	node->left = NULL;
	node->right= NULL;
	node->data = i;
}

struct listnode *getlistnode() {
	struct listnode * node = (struct listnode *) malloc(sizeof(struct listnode));
	node->sum = 0;
	node->prev = NULL;
	node->next = NULL;
}

void get_vertical_sum(struct treenode *root, struct listnode *node) {
	if(root) {
		node->sum += root->data;

		if(node->prev == NULL) {
			node->prev = getlistnode();
			node->prev->next = node;
		}
		get_vertical_sum(root->left, node->prev);

		if(node->next== NULL) {
			node->next = getlistnode();
			node->next->prev = node;
		}
		get_vertical_sum(root->right, node->next);
	}
}

void printsum(struct listnode *node) {
	while(node->prev) {
		node = node->prev;
		//printf("%d ", node->sum);
	}
	while(node) {
		printf("%d ", node->sum);
		node = node->next;
	}
}

void main() {
	struct treenode *root = getnode(5);
	root->left = getnode(4);
	root->left->left = getnode(3);
	root->left->right= getnode(8);
	root->right= getnode(7);
	root->right->left = getnode(6);
	root->right->right= getnode(9);

	struct listnode *node = getlistnode();
	get_vertical_sum(root, node);
	printsum(node);
}
