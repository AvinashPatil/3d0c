/* remove keys from a  **bst** which are out of range
*/

#include<stdio.h>
#include<stdlib.h>


struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
};

struct treenode * getnode(int i) {
	struct treenode *node  = (struct treenode *) malloc(sizeof(struct treenode));
	node->left= NULL;
	node->right= NULL;
	node->data = i;
	return node;
}

struct treenode * remove_nodes(struct treenode *root, int i, int j) {
	if(root) {

		remove_nodes(root->left, i, j);
		remove_nodes(root->right, i, j);

		if(root->left && root->left->data < i) {
			struct treenode *temp = root->left;
			root->left = root->left->right;
			free(temp);
		}

		if(root->right && root->right->data > j) {
			struct treenode *temp = root->right;
			root->right = root->right->left;
			free(temp);
		}
	}
}

void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void main() {
	struct treenode *root = getnode(10);
	root->left = getnode(5);
	root->right = getnode(15);
	root->left->left = getnode(3);
	root->left->right= getnode(4);
	root->left->left->left = getnode(-1);
	root->right->left = getnode(13);
	root->right->right= getnode(18);
	
	inorder(root);	
	remove_nodes(root, 5, 13);
	printf("\n");
	inorder(root);	
}
