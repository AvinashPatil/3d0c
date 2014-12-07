/* Program to find 'Lowest common ancestor'

And 
 To find the distance between two nodes

the formula is 
 dist between nodes = dist of n1 from root + dist of n2 from root - 2 * (distance of their LCA from root)
*/


#include<stdio.h>
#include<stdlib.h>

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

treenode * lca(treenode *root, int i, int j) {

	// base case
	if(root == NULL) {
		return NULL;
	}

	if(root->data == i || root->data == j) {
		return root;
	}

	treenode * l_node = lca(root->left, i, j);
	treenode * r_node = lca(root->right, i, j);

	if(l_node && r_node) {
		return root;
	}

	if(l_node) {
		return l_node;
	} else {
		return r_node;
	}
}


int find_level(treenode *node, int i , int level) {

	// base case

	// if we do not find node
	if(node == NULL) {
		return  -1;
		//return  0;
	}
		
	// if we find node
	if(node->data == i) {
		return level;
	}

	int l_level = find_level(node->left, i, level+1);
	
	if(l_level == -1)
		return find_level(node->right, i, level+1);
	else 
		return l_level;

}

int distance(treenode *root, int i, int j) {
	
	treenode *ancestor = lca(root, i, j);
	int l_lca, l_i, l_j;

	l_lca = find_level(root, ancestor->data, 0);
	l_i = find_level(root, i, 0);
	l_j = find_level(root, j, 0);

	return l_i + l_j - 2*l_lca;
}


void main() {

	treenode * root = get_treenode(1);
	root->left = get_treenode(2);
	root->right = get_treenode(3);
	root->left->left = get_treenode(4);
	root->left->right = get_treenode(5);
	root->right->left = get_treenode(6);
	root->right->right = get_treenode(7);

	treenode * node = lca(root, 6, 4);
	printf("lca of 6 and 4 is %d\n", node->data);

	printf("Distance between 6 and 1 is %d\n", distance(root, 6, 1));
}

