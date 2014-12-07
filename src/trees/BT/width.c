#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define Max(a, b) ((a>b)?a:b)

struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
};

struct treenode * getnode(int i){
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode ));
	memset(node, 0, sizeof(struct treenode));
	node->data = i;
}

int tree_height(struct treenode *root) {

	if(root == NULL) {
		return 0;
	}

	return 1 + Max(tree_height(root->left), tree_height(root->right));
}

void width(struct treenode *root, int count[], int level) {
	if(root == NULL) {
		return;
	}
	count[level]++;
	width(root->left, count, level+1);
	width(root->right, count, level+1);
}

int width_util(struct treenode *root, int count[], int h) {
	width(root, count, 0);
	int max = INT_MIN;
	for(int i=0; i<h; i++) {
		if(count[i] > max) {
			max = count[i];
		}
		printf("%d ", count[i]);
	}
	return max;
}

void main() {
	struct treenode *root = getnode(5);
	root->left = getnode(3);
	root->right= getnode(7);
	root->left->left = getnode(1);
	root->right->left= getnode(9);

	int h = tree_height(root);
	int count[h];

	for(int i=0; i<h; i++) {
		count[i] = 0;
	}
	printf("Width of tree is %d", width_util(root, count, h));
}
