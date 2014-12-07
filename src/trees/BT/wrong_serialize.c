/* Program to serialize and deserialize a tree 
Traverse the tree in pre-order fashion

*/
#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;


treenode * newnode(int i) {

	treenode *node = (treenode *) malloc(sizeof(treenode));
	node->data = i;
	node->left = NULL;
	node->right= NULL;
	return node;
}

int getsize(treenode *node) {

	static int size = 0;

	size++;
	if(node) {
		getsize(node->left);
		getsize(node->right);
	}

	return size;
	
}

void serialize(treenode *node, int a[], int len) {
	static int i = 0;
	if(node == NULL) {
		a[i++] = -1; 
	} else {
		a[i++] = node->data; 
		serialize(node->left, a, len);
		serialize(node->right, a, len);
	}
}

treenode * deserialize(int a[], treenode **node) {
	static int i = 0;
	if(a[i] == -1) {
		return NULL;
	} else {
		*node = newnode(a[i++]);
		(*node)->left = deserialize(a, &(*node)->left);
		(*node)->right = deserialize(a, &(*node)->right);
		return *node;
	}
}

void printarray(int a[], int len) {
	for(int i= 0; i<len; i++) {
		printf("%d ", a[i]);
	}	
	printf("\n");
}

void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);	
		inorder(root->right);
	}
	
}

void main() {
	treenode *root = newnode(5);
	root->left = newnode(2);
	root->right = newnode(7);
	root->left->right = newnode(4);
	root->left->right->left = newnode(3);

	int n = getsize(root);
	//inorder(root);
	int a[n];
	serialize(root, a, n);
	printarray(a, n);
	treenode *root1 = NULL;
	deserialize(a, &root1);
	printf("\n");
	inorder(root1);
	printf("\n");
	
	int b[n];
	serialize(root1, b, n);
	//printarray(b, n);
}

