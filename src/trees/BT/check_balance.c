/* Program to check if a tree is balanced like RB tree.
Means min_heaight * 2 > max_height

Also there is condition that we have to traverse the tree only once


*****Program is not correct. Has to checked once more.

http://www.geeksforgeeks.org/check-given-binary-tree-follows-height-property-red-black-tree/

*/




#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
}treenode;

treenode * get_treenode(int i) {
	treenode *node = (treenode *)malloc(sizeof(treenode));
	node->left = NULL;
	node->right= NULL;
	node->data = i;
	return node;
}

bool check_balanced(treenode *root, int *minh, int *maxh) {

	// base case
	if(root == NULL) {
		*minh = *maxh = 0;
		return true;
	}

	int l_maxh, l_minh;
	int r_maxh, r_minh;
	
	if(check_balanced(root->left, &l_minh, &l_maxh) == false)
		return false;
	if(check_balanced(root->right, &r_minh, &r_maxh) == false)
		return false;

	*minh = 1 + min(l_minh, r_minh);

	*maxh = 1 + max(l_maxh, r_maxh);

	if(*maxh <=  2 * (*minh)) {
		//printf("Min = %d max = %d", *minh, *maxh);
		return true;
	}

	printf("Min = %d max = %d", *minh, *maxh);
	return false;
}

void main() {
	treenode *root = get_treenode(10);

	root->left = get_treenode(5);
	root->left->left = get_treenode(2);
	
	root->right = get_treenode(100);
	root->right->left = get_treenode(50);
	root->right->right = get_treenode(150);
	root->right->left->left = get_treenode(40);

	int minh = INT_MAX, maxh = INT_MIN;

	if(check_balanced(root, &minh, &maxh)) {
		printf("Tree is balanced");
	} else {
		printf("Tree is not balanced");
	}
}

