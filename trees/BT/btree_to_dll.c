#include<stdio.h>
#include<stdlib.h>

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

static treenode *prev = NULL; 

void btree_to_dll(treenode *root, treenode **head) {

	if(root) {
	
		btree_to_dll(root->left, head);

		if(prev == NULL) {
			*head = root;
		} else {
			// In postorder this logic will change. It works for inorder and preorder.
			// Because in postorder  only we visit root last.
			root->left = prev;
			prev->right = root;
		}

		prev = root;
		
		btree_to_dll(root->right, head);
	}	
}	

void printdll(treenode *head) {
	
	printf("The DLL is as : ");
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->right;
	}
	printf("\n");
}

void main() {
	treenode *root    = get_treenode(10);
	root->left        = get_treenode(12);
	root->right       = get_treenode(15);
	root->left->left  = get_treenode(25);
	root->left->right = get_treenode(30);
	root->right->left = get_treenode(36);

	treenode *head = NULL;
	
	btree_to_dll(root, &head);

	printdll(head);
}
