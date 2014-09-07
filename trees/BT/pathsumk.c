/* This programs prints path which susm to k in a tree
Learnings : 
	1. Variable size array has to be initialized explicitly by memset and not by '={0}'. Compiler does not know how much to initialize!!
Time taken:
	1. Wrong newnode argument	
	2. Wrong MAX definition
	3, Call to printpath was not correct. Missed parameter. Also its implementation. Did not use interator i properly.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX(a,b) (a>b ? a : b)

struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
};

struct treenode * newnode(int i) {
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode));
	node->data = i;
	node->left = NULL;
	node->right= NULL;
	return node;
}

void printpath(int path[], int level, int i) {
	for(; i<=level; i++) {
		printf(" %d ", path[i]);
	}
	printf("\n");
}

void printpathk(struct treenode *root, int k, int path[], int level)  {

	if(root == NULL) {
		return;
	}

	path[level] = root->data;
	//printf("path[%d] = %d", level, path[level]);

	int sum = 0;
	for(int i = level; i>=0; i--) {
		sum += path[i];
		if(sum == k) {
			printpath(path, level, i);
		}
	}
	
	printpathk(root->left, k, path, level+1);
	printpathk(root->right, k, path, level+1);
}

int treedepth(struct treenode *root) {
	if(root == NULL) {
		return 0;
	}
	return 1 + MAX(treedepth(root->left), treedepth(root->right));
}

void main() {
	struct treenode *root = newnode(7);
	root->left = newnode(5);
	root->left->right = newnode(4);
	root->left->left = newnode(3);
	root->right = newnode(8);
	root->right->left = newnode(9);
	root->right->right= newnode(6);
	int depth = treedepth(root);
	
	// define path
	int path[depth];
	memset(path, 0, sizeof(int)*depth);

	//printf("Depth is %d", treedepth(root));

	printpathk(root, 17, path, 0);

}




