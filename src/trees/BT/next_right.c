/* Program to print the next right
*/

#include<stdio.h>
#include<stdlib.h>
#include<queue>


#define MAX 100

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

struct node_queue {

	int front, rear;
	treenode * node[MAX];
};

struct level_queue {
	
	int front, rear;
	int level[MAX];
};

struct node_queue * create_node_queue() {
	struct node_queue * Q = (struct node_queue *) malloc(sizeof(struct node_queue *));
	front = rear = 0;
	for(int i=0; i<MAX; i++) {
		Q->node[i] = NULL;
	}
	return Q;
}

struct level_queue * create_level_queue() {
	struct level_queue* L = (struct level_queue *) malloc(sizeof(struct level_queue *));
	front = rear = 0;
	memset(L->level, 0, L->level * sizeof(int));	
	return L;
}



bool isEmpty(struct node_queue *Q) {
	return(Q->front == Q->rear);
}

treenode *  next_right(treenode *root, int k) {

	struct node_queue *Q = create_node_queue();
	struct level_queue *L = create_level_queue();

	push_rear(Q, root);
	push_rear(L, 0);

	while(!isEmpty(Q)) {

		// Standard BFS for Binary tree

		// Pop the node from Q
		treenode *node = remove_front(Q);
		int level = remove_front(L);
		
		// Do the checking
		if(node->data == k) {
			if(isEmpty(Q) || get_front(L) != level) {
				// this means either Q is empty
				// or the next element in Q is of different level
				// it means that his is righmost node in the tree at this level
				return NULL;
			}
			else {
				return (remove_front(Q));
			}
		}
		
		// Push its children
		if(node->left) {
			push_rear(Q, node->left);
			push_rear(L, level+1);
		}

		if(node->right) {
			push_rear(Q, node->right);
			push_rear(L, level+1);
		}
	}

	return NULL;
}	


void main() {
	treenode *root = get_treenode(10);
	root->left = get_treenode(2);
	root->right = get_treenode(6);
	root->right->right = get_treenode(5);
	root->left->left = get_treenode(8);
	root->left->right = get_treenode(4);

	next_right(root, 2);
}


