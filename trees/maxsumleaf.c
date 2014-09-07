/*
	Program to print the max sum path from root.

Learnings: 
	1. Use proper name for treenode
	2. Always check the node == NULL  condition in tree recursion.

Time taken:
	1. In findmaxleaf
		To indetify weather to return a treenode from or to use a double pointer instead. Should use always a double pointer to change any variable in recursion. Its an output argument.


*/


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right; 
};



struct treenode * newnode(int i) {
	struct treenode *node =  (struct treenode *) malloc(sizeof(struct treenode));
	node->data = i;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int maxsum = 0;

void findmaxleaf(struct treenode * node, int sum, struct treenode **maxleaf) {

	if(node == NULL) {
		return;
	}

	int cursum = sum + node->data;
	
	if(node->left == NULL && node->right == NULL) {
		if(cursum > maxsum) {
			maxsum = cursum;
			*maxleaf = node;
		}
	}
	findmaxleaf(node->left, cursum, maxleaf);
	findmaxleaf(node->right, cursum, maxleaf);
}


bool printpath(struct treenode *node, struct treenode *leaf) {
	
	if(node == NULL) {
		return false;
	}
	if(node == leaf || printpath(node->left, leaf) || printpath(node->right, leaf)) {
		printf("%d ", node->data);
		return true;
	}
	return false;
}

void findmaxpath(struct treenode *root) {
	struct treenode *maxleaf; 
	findmaxleaf(root, 0, &maxleaf);
	printpath(root, maxleaf);
}


void main() {
	struct treenode * root;

	root = newnode(7);
	root->left = newnode(3);
	root->right = newnode(-4);
	root->left->right = newnode(8);
	root->right->left = newnode(2);

	findmaxpath(root);
}

