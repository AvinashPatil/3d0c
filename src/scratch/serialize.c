#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

struct treenode {
	struct treenode *left;
	struct treenode *right;
	int data;
};

struct treenode * getnode(int data) {
	struct treenode * node = (struct treenode *) malloc(sizeof(struct treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = data;
	return node;
}

struct queue {
	struct treenode *item[MAX];
	int front, rear;
};

void initialize(struct queue *Q) {
	Q->front = 0;
	Q->rear = 0;
	for(int i=0; i<MAX; i++) {
		Q->item[i]  = NULL;
	}
}

bool isEmpty(struct queue *Q) {
	return(Q->front == Q->rear);
}

void append_front(struct queue *Q, struct treenode *node) {
	Q->item[Q->front] = node;
	Q->front += 1;
}

struct treenode * remove_rear(struct queue *Q) {
	if(!isEmpty(Q)) {
		struct treenode *temp = Q->item[Q->rear];
		Q->rear += 1;
		return temp;
	}
	return NULL;
}

void print_inorder(struct treenode *root) {
	if(root) {
		print_inorder(root->left);
		printf("%d ", root->data);
		print_inorder(root->right);
	}
}

int  serialize(struct treenode *root, struct queue *Q, int a[]) {

	int i = 0;
	append_front(Q, root);	
	while(!isEmpty(Q)) {
		struct treenode *temp = remove_rear(Q);
		
		if(temp) {
			a[i] = temp->data;
		} else {
			a[i] = -1;
		}
		i++;
		
		if(temp) {
			append_front(Q, temp->left);
			append_front(Q, temp->right);
		} else {
			append_front(Q, NULL);
		}
	}
	return i-1;
}

struct treenode * deserialize(struct queue *Q, int a[], int len) {

	struct treenode *root =  getnode(a[0]);
	append_front(Q, root);
	int i=0;
	while(!isEmpty(Q) && i<=len) {
		struct treenode *temp = remove_rear(Q);
		if(temp) {
			if(a[i] != -1) {
				temp->left = getnode(a[i]);
				append_front(Q, temp->left);
			} else {
				temp->left = NULL;
			}
			i++;

			if(a[i] != -1) {
				temp->right= getnode(a[i]);
				append_front(Q, temp->right);
			} else {
				temp->right = NULL;
			}
			i++;
		}
	}
	return root;
}


void main() {
	struct treenode *root = getnode(10);
	root->left = getnode(5);
	root->left->left = getnode(3);
	root->right = getnode(15);
	root->right->right = getnode(18);
	//print_inorder(root);
	struct queue Q;
	int a[MAX] = {0};
	initialize(&Q);
	int index = serialize(root, &Q, a);

	for(int i=0; i<=index; i++) {
		printf("%d ", a[i]);
	}

	/*struct treenode *root1;
	root1=deserialize(&Q, a, index); 
	print_inorder(root1);*/
}

