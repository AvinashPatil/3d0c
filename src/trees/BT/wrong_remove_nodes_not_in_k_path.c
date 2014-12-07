/* Program to remove the nodes that not lie in paths sum to k

WRONG SOLUTION!!!

Look at link below
http://www.geeksforgeeks.org/remove-all-nodes-which-lie-on-a-path-having-sum-less-than-k/
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
        int data;
        struct treenode *left;
        struct treenode *right;
}treenode;


treenode * newNode(int i) {
        treenode *node = (treenode *)malloc(sizeof(treenode));
        node->left = NULL;
        node->right= NULL;
        node->data = i;
        return node;
}


treenode * remove_nodes(treenode *root, int k, int cur_sum) {
	if(root) {
		root->left = remove_nodes(root->left, k, cur_sum + root->data);
		root->right = remove_nodes(root->right, k, cur_sum + root->data);

		if(root->left == NULL && root->right == NULL && (cur_sum+root->data) < k) {
			free(root);
			root = NULL;
		}
		return root;
	}
}


void print_tree(treenode *root) {
	if(root) {
		print_tree(root->left);
		printf("%d ", root->data);	
		print_tree(root->right);
	}
}

void main() {

	int k = 45;
	struct treenode *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->left->right = newNode(9);
	root->left->right->left = newNode(12);
	root->right->right->left = newNode(10);
	root->right->right->left->right = newNode(11);
	root->left->left->right->left = newNode(13);
	root->left->left->right->right = newNode(14);
	root->left->left->right->right->left = newNode(15);

	printf("Before removal");
	print_tree(root);
	printf("\nAfterremoval");
	remove_nodes(root, k, 0);
	print_tree(root);
}
