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

void inorder_iterative(struct treenode *root, int target) {
	struct stack S1;
	struct stack S2;
	initialize_stack(&S1);
	initialize_stack(&S2);

	bool done1 = true;
	bool done2 = true;

	int val1 = 0;
	int val2 = 0;

	struct treenode *root1 = root;
	struct treenode *root2 = root;

	while(true) {

		while(done1) {
			if(root1) {
				push(&S1, root1);
				root1 = root1->left;
			} else {
				if(!isEmpty(&S1)) {
					root1 = pop(&S1);
					//printf("%d ", root->data);
					val1 = root1->data;
					root1 = root1->right;
					done1 = false;
				} else {
					done1 = false;
				}
				
			}
		}

		while(done2) {
			if(root2) {
				push(&S2, root2);
				root2 = root2->right;
			} else {
				if(!isEmpty(&S2)) {
					root2 = pop(&S2);
					//printf("%d ", root->data);
					val2 = root2->data;
					root2 = root2->left;
					done2 = false;
				} else {
					done2 = false;
				}
			}
		}

		if(val1 != val2 && val1+val2 == target) {
			printf(" %d  %d", val1, val2);
			return;
		}
		if(val1+val2 < target) {
			// resume normal traversal
			done1 = true;
		} else if(val1+val2 > target) {
			// resume reverse traversal
			done2 = true;
		} else {
			return;
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
	inorder_iterative(root, 20);
}
