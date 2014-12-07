#include<stdio.h>
#include<stdlib.h>

typedef struct treenode {
	int data;
	struct treenode *left;
	struct treenode *right;
	struct treenode *nextRight;
} treenode;

treenode * newnode(int i) {
	treenode *node = (treenode *) malloc(sizeof(treenode));
	node->left = NULL;
	node->right= NULL;
	node->nextRight = NULL;
	node->data = i;
	return node;
}


// This function returns the leftmost child of the node at the same level as P
treenode * getnextRight(treenode *node) {
	treenode *temp = node->nextRight;

	while (temp != NULL) {
		if(temp->left) {
			return temp->left;
		}
		if(temp->right) {
			return temp->right;
		}
		temp = temp->nextRight;
	}
	return NULL;
}

/* p is for levels
q is for each level
connect a level first and then go to next level
*/		

void connect(treenode *root) {

	treenode *p, *q;
	p = q = root;
	
	while (p != NULL) {
		q = p;
		while (q != NULL) {
			if (q->left) {
				if (q->right) {
					q->left->nextRight = q->right;
				} else {
					q->left->nextRight = getnextRight(q);
				}
			}

			if (q->right) {
				q->right->nextRight = getnextRight(q);
			}

			q = q->nextRight;
		}

		if (p->left) {
			p = p->left;
		} else if (p->right) {
			p = p->right;
		} else {
			p = getnextRight(p);
		}
	}
}

void printtree(treenode *node) {
	
	if(node!= NULL) {
		printtree(node->left);
		printf("%d-->", node->data);
		if(node->nextRight) {
			printf("%d \n", node->nextRight->data);
		}	
		printtree(node->right);
	}
}

void main() {
	treenode *root = newnode(3);
	root->left = newnode(4);
	root->right= newnode(6);
	root->left->right = newnode(8);
	root->right->left = newnode(7);
	root->right->right= newnode(9);

	connect(root);	
	
	printtree(root);
}
