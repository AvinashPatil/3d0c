#include<stdio.h>
#include<stdlib.h>
#define max(a,b) ((a>b)?a:b)


struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
};


struct treenode * getnode(int i) {
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = i;
	return node;
}

void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


int height(struct treenode *root) {
	if(root ==  NULL) {
		return 0;
	}
	return 1+max(height(root->left), height(root->right));
}

/*
	Diameter of tree is maximum distance between any two nodes in tree
	Its maximum of
	1. height of left subtree + height of right subtree +1
	2. Max(diameter of left subtree, diameter of right subtree)
	
	why 2 is required?
	As the diameter path may not always go through root :-)
*/

int diameter(struct treenode *root) {
	if(root == NULL) {
		return 0;
	}
	
	int l_height = height(root->left);
	int r_height = height(root->right);

	int l_dia = diameter(root->left);
	int r_dia = diameter(root->right);

	return max(l_height+r_height+1, max(l_dia, r_dia));

}

void main() {

	struct treenode *root = getnode(10);
	root->left = getnode(5);
	root->right = getnode(15);
	root->left->left = getnode(3);
	root->left->right = getnode(7);
	root->right->left = getnode(13);
	root->right->right = getnode(17);
	//inorder(root);

	printf("%d ", diameter(root));
}
