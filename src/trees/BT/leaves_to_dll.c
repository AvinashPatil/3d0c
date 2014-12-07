/* Program to extract leaves of a Tree and form a doubly linked list. Note that the nodes have to be removed from the tree.

This program is built upon same logic as btree_to_dll.c

http://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
        int data;
        struct treenode *left;
        struct treenode *right;
} treenode;

treenode * get_treenode(int i) {
        treenode *node = (treenode *)malloc(sizeof(treenode));
        node->left = NULL;
        node->right= NULL;
        node->data = i;
        return node;
}

static treenode * prev = NULL;

treenode * leaves_to_dll(treenode * root, treenode **head) {

	if(root) {
		if(root->left == NULL && root->right == NULL) {

			if(prev == NULL) {
				*head = root;
			} else {
				prev->right = root;
				root->left = prev;
			}

			prev = root;
			return NULL;
		}
		root->left = leaves_to_dll(root->left, head);
		root->right = leaves_to_dll(root->right, head);
		return root;
	}
}

void print_dll(treenode * node) {

	while(node) {
		printf("%d ", node->data);
		node = node->right;
	}
}

void inorder(treenode *root) { 
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


void main() {
	struct treenode *root = get_treenode(1);
	root->left = get_treenode(2);
	root->right = get_treenode(3);
	root->left->left = get_treenode(4);
	root->left->right = get_treenode(5);
	root->right->right = get_treenode(6);
	root->left->left->left = get_treenode(7);
	root->left->left->right = get_treenode(8);
	root->right->right->left = get_treenode(9);
	root->right->right->right = get_treenode(10);


	printf("Inorder before :");

	inorder(root);

	treenode *head = NULL;
	root = leaves_to_dll(root, &head);
	printf("\nThe DLL :");
	print_dll(head);

	printf("\n Inorder after :");
	inorder(root);
}


