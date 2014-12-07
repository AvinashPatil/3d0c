#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max(a,b) ((a>b)?a:b)
#define SIZE 100



struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
};

struct stack {
	int top;
	struct treenode *item[SIZE];
};

struct treenode * getnode(int i) {
	struct treenode *node = (struct treenode *) malloc(sizeof(struct treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = i; 
	return node;
}

void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void initialize_stack(struct stack *S) {
	S->top = -1;
	for(int i=0; i<SIZE; i++) {
		S->item[i] = NULL;
	}
}

void push(struct stack *S, struct treenode *node) {
	S->top++;
	S->item[S->top] = node;
}

struct treenode * pop(struct stack *S) {
	struct treenode *node = S->item[S->top];
	S->top--;
	return node;
} 

bool isEmpty(struct stack *S) {
	if(S->top == -1) {
		return true;
	}
	return false;
}

void inorder_iterative(struct treenode *root) {
	struct stack S;
	initialize_stack(&S);

	while(true) {
		if(root) {
			push(&S, root);
			root = root->left;
		} else {
			if(!isEmpty(&S)) {
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
	root->left = getnode(5);
	root->right = getnode(15);
	root->left->left = getnode(3);
	root->left->right = getnode(7);
	root->right->left = getnode(13);
	root->right->right = getnode(17);
	//inorder(root);
	inorder_iterative(root);

}
