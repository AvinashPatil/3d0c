#include<stdio.h>
#include<stdlib.h>


struct treenode {
        struct treenode *left;
        struct treenode *right;
        int data;
};

struct treenode * getnode(int i) {
        struct treenode *node  = (struct treenode *) malloc(sizeof(struct treenode));
        node->left= NULL;
        node->right= NULL;
        node->data = i;
        return node;
}


struct treenode * lca(struct treenode *root, int i, int j) {
	if(root) {
		if(root->data == i || root->data == j) {
			return root;
		}

		struct treenode *left = NULL;
		struct treenode *right= NULL;

		left = lca(root->left, i, j);
		right= lca(root->right, i, j);

		if(left && right) {
			return root;
		}

		if(left) {
			return left;
		} else {
			return right;
		}

	}
	return NULL;
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
        root->left->right= getnode(4);
        root->left->left->left = getnode(-1);
        root->right->left = getnode(13);
        root->right->right= getnode(18);

        inorder(root);
	//struct treenode *temp = lca(root, 5, 13);
	struct treenode *temp = lca(root, -1, 3);
        printf("\nLCA is %d ", temp->data);
}

