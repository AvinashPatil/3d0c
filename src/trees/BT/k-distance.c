#include<stdio.h>
#include<stdlib.h>


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

void  print_k_distance_down(struct treenode *root, int k) {

	if (root == NULL || k <0) {
		return;
	}

	if (k==0) {
		printf("%d ", root->data);
	}

	print_k_distance_down(root->left, k-1);
	print_k_distance_down(root->right, k-1);
}

int get_k_distance(struct treenode *root, struct treenode *node, int k) {
	// base case
	if(root == NULL) {
		// we didnt not found the node so far 
		return -1; 
	}

	if(root == node) {
		// we found the target node; node print all nodes below it k distcance away
		print_k_distance_down(root, k);
		return 0;
	}

	int dl = get_k_distance(root->left, node, k);

	if(dl != -1) {  // this means we have found target node in left subtree
		
		if(dl+1 == k) {
			// check if left child is k-1 distance away, it means this node is k distance away
			printf("%d ", root->data);
		} else {
			// if not then search right subtree 
			print_k_distance_down(root->right, k-dl-2);
		}
		// return distance of this node
		return dl+1;
	}
	
	int dr = get_k_distance(root->right, node, k);

	if(dr != 0) {

		if(dr+1 == k) {
			printf("%d ", root->data);
		} else {
			print_k_distance_down(root->left, k-dr-2);
		}
		return dr+1;
	}
	
	return -1;
}


void inorder(struct treenode *root) {
	if(root) {
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
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

	//get_k_distance(root, root->right->right, 2);
	get_k_distance(root, root->right, 2);
}

