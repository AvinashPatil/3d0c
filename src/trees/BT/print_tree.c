#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


int paren_count = 0;
bool parent = false;
void print_tree(treenode *root) {
	
	if(root) {
		if(parent == false) {
			printf("Parent");
			parent = true;
		}
		if(root->left) {	
			printf("(");
			printf("left");
			paren_count++;
			print_tree(root->left);
		}
		if(root->right) {
			if(paren_count <= 1) {
				printf("(");
				paren_count++;
			}
			printf("right");
			print_tree(root->right);
		}
		if(paren_count > 0) {
			printf(")");
			paren_count--;
		}	
	}
	
}

void main() {
        treenode *root    = get_treenode(10);
        root->left        = get_treenode(12);
        root->right       = get_treenode(15);
        root->left->left  = get_treenode(25);
        root->left->right = get_treenode(30);
        root->right->left = get_treenode(36);
	
	print_tree(root);
}
