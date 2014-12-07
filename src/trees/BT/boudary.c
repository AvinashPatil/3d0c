#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode; 

treenode * newnode(int i) {
	treenode *node = (treenode *)malloc(sizeof(treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = i;
	return node;
}

void printleft(treenode * node) {
	if(node == NULL) {
		return;
	}
	if (node->left) {
		printf(" %d ", node->data);	
		printleft(node->left);
	} else if (node->right) {
		printf(" %d ", node->data);	
		printleft(node->right);
	}
}

void printright(treenode *node) {
	if(node == NULL) {
		return;
	}
	if (node->right) {
		printright(node->right);
		printf(" %d ",node->data);
	} else if (node->left) {
		printright(node->left);
		printf(" %d ",node->data);
	}
}

void printleaves(treenode *node) {
	if(node == NULL) {
		return;
	}	

	if(node->left == NULL && node->right == NULL) {
		printf(" %d ", node->data);
		return;
	}
	printleaves(node->left);
	printleaves(node->right);
}

void printboundary(treenode *root) {
	printleft(root);
	printleaves(root);
	printright(root);
}

void main() {
	treenode * root = newnode(3);
	root->left = newnode(1);	
	root->right = newnode(5);	
	root->left->right = newnode(6);
	root->left->right->left = newnode(9);
	root->left->right->right= newnode(4);
	root->right->right= newnode(2);
	root->right->right->left= newnode(7);
	root->right->right->right= newnode(8);
		
	printboundary(root);

}
