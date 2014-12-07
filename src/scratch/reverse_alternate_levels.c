/* reverse the alternate levels in a binary tree */

#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct treenode {
	struct treenode *left;
	struct treenode *right;
	char data;
};

struct treenode * newNode(char c) {
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = c;
	return node;
}

void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

void store_inorder(struct treenode *root, char a[], int *index, int level) {
	if(root) {
		store_inorder(root->left, a, index, level+1);
		if(level%2 != 0) {
			a[(*index)++] = root->data; 
		}
		store_inorder(root->right, a, index, level+1);
	}
}

void reverse(char a[], int start, int end) {

	while(start<end) {
		char temp;
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}

}

void store_back_inorder(struct treenode *root, char a[], int *index, int level) {

	if(root) {
		store_back_inorder(root->left, a, index, level+1);
		if(level%2 != 0) {
			root->data = a[(*index)++];
		}
		store_back_inorder(root->right, a, index, level+1);
	}
}

void reverse_alternate(struct treenode *root) {
	char a[MAX];
	int index = 0;
	store_inorder(root, a, &index, 0);
	reverse(a, 0, index-1);
	index = 0;
	store_back_inorder(root, a, &index, 0);
}

void main() {
	struct treenode *root = newNode('a');
	root->left = newNode('b');
	root->right = newNode('c');
	root->left->left = newNode('d');
	root->left->right = newNode('e');
	root->right->left = newNode('f');
	root->right->right = newNode('g');
	root->left->left->left = newNode('h');
	root->left->left->right = newNode('i');
	root->left->right->left = newNode('j');
	root->left->right->right = newNode('k');
	root->right->left->left = newNode('l');
	root->right->left->right = newNode('m');
	root->right->right->left = newNode('n');
	root->right->right->right = newNode('o');

	inorder(root);
	printf("\n");
	reverse_alternate(root);
	inorder(root);
}
