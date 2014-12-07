
/* Given a stream of integers periodically you want to  get the rank(i) of any previous integer.


Note that this problem asks get rank of an element in O(logn). 
We can find rank of a node in O(n) time using normal inorder traversal.
We can also find the kth element using inorder traversal.

Here we using the BST property and change the data structure to store additional information about size of left subtree.

	
		READ THIS PROGRAM CAREFULLY!!

Learnings :
	1. where to increment left_size
	2. How 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
	int left_size;
} treenode;

treenode * newnode( int data) {
	treenode *node = (treenode *) malloc(sizeof(treenode));
	memset(node, 0, sizeof(treenode));
	node->data = data;
}	


// this insert in BST

treenode * insert(treenode * root, int i) {
	if(root == NULL) {
		return newnode(i);
	} else {
		if(i < root->data) {
			root->left_size++;
			root->left = insert(root->left, i);
		} else {
			root->right = insert(root->right, i);
		}
		return root;
	}
}

void inorder(treenode *node) {
	if(node == NULL)
		return;

	inorder(node->left);
	printf("%d ", node->left_size);
	//printf("%d ", node->data);
	inorder(node->right);
}

/*
	Note that this is BST traversal. 
So we do not visit all the nodes in tree. This is in contrast to other tree travesals in which we happen to visit all the nodes.
*/

int getrank(treenode *node, int i) {
	if(node == NULL) {
		// error case
		// data not found
		return -1;
	}	
		
	if(node->data == i) {
		return node->left_size;
	}

	if(i < node->data) {
		// goto left
		return getrank(node->left, i);
	}

	if(i > node->data) {
		// goto right
		int right;
		if((right = getrank(node->right, i)) == -1) {
			return -1;
		}
		//return node->left_size + 1 + getrank(node->right, i); 
		return node->left_size + 1 + right;
	}
}

void main() {
	int a[]={5, 6, 3, 1, 8, 4, 7};
	int len = sizeof(a)/sizeof(a[0]);

	treenode * root = NULL;
	for(int i=0; i< len; i++) {
		root = insert(root, a[i]);
	}
	inorder(root);
	//printf("Rank is %d", getrank(root, 8));
}

