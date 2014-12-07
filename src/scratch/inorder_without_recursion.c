/* Inorder traversali of a tree  with stack */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100


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

struct stack {
	int top;
	struct treenode *item[MAX]; 
};

void initialize(struct stack *S) {
	S->top = -1;
	for(int i=0; i<MAX; i++) {
		S->item[i] = NULL;
	}
}

bool isEmpty(struct stack *S) {
	return (S->top == -1);
}

void push(struct stack *S, struct treenode *node) {
	S->top++;
	S->item[S->top] = node;
	return;
}

struct treenode * pop(struct stack *S) {
	if(!isEmpty(S)) {
		struct treenode *node = S->item[S->top];
		S->top--;
		return node;
	} else {
		return NULL;
	}
}

void inorder(struct treenode *root) {

	if(root) {
		struct stack S;
		initialize(&S);

		while(true) {
			if(root) {
				push(&S, root);
				root = root->left;
			} else if(!isEmpty(&S)) {
				root = pop(&S); 
				printf("%d ", root->data);
				root = root->right;
			} else {
				break;
			}
		}
	}
}

void main() {
	struct treenode *root = getnode(10);

	root->left = getnode(4);
	root->left->left = getnode(3);
	root->left->right= getnode(5);
	root->right= getnode(15);
	root->right->left= getnode(13);
	root->right->right= getnode(18);

	inorder(root);
}
