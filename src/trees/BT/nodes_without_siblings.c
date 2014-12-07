/* Program to print the nodes whoch do not have siblings
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

void printSingles(treenode * root) {

	if(root) {
		printSingles(root->left);
		printSingles(root->right);

		if(root->left && root->right == NULL) {
			printf("Node without sibling is %d\n", root->left->data);
		}

		if(root->right && root->left== NULL) {
			printf("Node without sibling is %d\n", root->right->data);

		}
	}

}	


void main() {
	treenode *root = get_treenode(1);
	root->left = get_treenode(2);
	root->right = get_treenode(3);
	root->left->right = get_treenode(4);
	root->right->left = get_treenode(5);
	root->right->left->left = get_treenode(6);
	printSingles(root);
}

