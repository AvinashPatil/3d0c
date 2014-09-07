/* 

Learnings: 
1. Always maintain stack of nodes and not of values
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define  MAX 100


typedef struct treenode {
	int data;
	struct treenode *left;	
	struct treenode *right;	
}treenode;


typedef struct stack {
	int top;
	treenode *node[MAX];
}stack;

void initialize(stack *s) {
	//stack is empty
	s->top = -1;
	//memset(s->node, 0 , sizeof(s->node));
}

bool isEmpty(stack *s) {
	if(s->top == -1)
		return true;
	return false;
}

void  push(stack * s, treenode *node) {
	if(s->top == MAX -1) {
		return ;
	}
	s->top++;
	s->node[s->top] = node;
	return;  
}

treenode * pop(stack *s) {
	if(isEmpty(s))
		return NULL;
	s->top--;
	return s->node[s->top + 1];	
}


treenode * newnode(int i) {
	treenode * node = (treenode *) malloc (sizeof(treenode));
	node->left = NULL;
	node->right= NULL;
	node->data = i;
	return node;
}


void spiral(treenode *root) {
	struct stack s1, s2;

	initialize(&s1);
	initialize(&s2);

	push(&s1, root);
	
	while(!isEmpty(&s1) || !isEmpty(&s2)) {

		while(!isEmpty(&s1)) {
			treenode * temp = pop(&s1);
			printf("%d ", temp->data);
			if(temp->left) {
				push(&s2, temp->left);
			}
			if(temp->right) {
				push(&s2, temp->right);
			}
		}

		while(!isEmpty(&s2)) {
			treenode * temp = pop(&s2);
			printf("%d ", temp->data);
			if(temp->right) {
				push(&s1, temp->right);
			}
			if(temp->left) {
				push(&s1, temp->left);
			}
		}
	}
}

void main() {
	treenode * root = newnode(1);

	root->left =  newnode(2);
	root->right = newnode(3);
	root->right->right = newnode(4);
	root->right->left= newnode(5);
	root->left->right = newnode(6);
	root->left->left= newnode(7);
	root->left->left->left= newnode(8);
	spiral(root);
}
