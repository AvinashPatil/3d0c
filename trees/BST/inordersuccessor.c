#include<stdio.h>
#include<stdlib.h>


struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
	struct treenode *parent;
	
};

struct treenode *  newnode(int i, struct treenode *parent) {
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode));
	node->data = i;
	node->left = NULL;
	node->right= NULL;
	node->parent= parent;
}

struct treenode * leftmost(struct treenode *node) {
	if(node == NULL) {
		return NULL;
	} 
	while(node->left != NULL)
		node = node->left;
	return node;
}

struct treenode * findinodersucc(struct treenode *node) {

	if(node == NULL)
		return NULL;
	// check if this node has right child and no parent

	if(node->parent == NULL || node->right != NULL) {
		return leftmost(node->right);
	} else {
	 	struct treenode *p = node->parent;
		while(p->left != node) {
			p = node->parent;
			node = p;
		}
		return p;
	}
}

void main() {

	struct treenode *root = newnode(5, NULL);
	root->left = newnode(7, root);
	root->left->left = newnode(2, root->left);
	root->right = newnode(3, root);
	root->right->left = newnode(3, root->right);

	struct treenode *result;
	result = findinodersucc(root);
	printf("%d ", result->data);
	result = findinodersucc(root->left->left);
	printf("%d ", result->data);
	result = findinodersucc(root->right->left);
	printf("%d ", result->data);
	
}
