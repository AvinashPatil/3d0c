/*
	Find if two nodes in a tree a swapped in a given BST.
	
	Learnings : 
	1. Inorder while putting in array use static variable. 
	2. initialize  index to array  as -1. first, middle and last in this case.	

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
}treenode;


treenode * newnode(int i) {
	treenode *node = (treenode *) malloc(sizeof(treenode));
	node->left = NULL;
	node->right= NULL;
	node->data = i;
	return node;
}

int getsize(treenode *node) {
	static int size = 0;
	if(node) {
		size++;
		getsize(node->left);
		getsize(node->right);
	}

	return size;
}

void inorder(treenode *node, int a[], int len) {
	static int cur_index = 0;
	if(node) {
		inorder(node->left, a, len);
		a[cur_index++] = node->data;
		inorder(node->right, a, len);
	}
} 
	
void printa(int a[], int len) {
	for(int i = 0; i<len; i++) {
		printf("%d ", a[i]);
	}
}

void findswaps_util(int a[], int len, int *first, int *middle, int *last) {

	int prev = 0;

	for(int i=1; i<len; i++) {
		// check if this is first instance of swapping
		if((a[i]<a[prev]) && *first == -1) {
			*first = prev;
			*middle = i;
		} 

		// check if this is second instance
	 	else if(a[i] < a[prev]) {
			*last = i;
		}
		prev = i;
	}
}

void findswaps(treenode *root) {

	int len = getsize(root);

	//printf("tree size is %d", len);

	int a[len];
	memset(a, 0, len*sizeof(a[0]));

	inorder(root, a, len);
	printa(a, len);	
	int first, middle, last;
	first = middle = last = -1;
	findswaps_util(a, len, &first, &middle, &last);
	if(first != -1 && last != -1) {
		printf("swapped nodes are %d and %d", a[first], a[last]);
	} else if(first != -1 && middle != -1) {
		printf("swapped nodes are %d and %d", a[first], a[middle]);
	}
}	

void main() {
	treenode * root = newnode(5);

	root->left = newnode(3);
	root->right= newnode(7);

	root->left->left = newnode(2);
	root->left->right= newnode(8);

	root->right->left = newnode(6);
	root->right->right= newnode(4);
	
	findswaps(root);

}
