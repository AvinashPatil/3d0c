#include <stdio.h>

struct emp_info emp[100] = {   {1, "E1", 4, 50, 4}, 
	{2, "E2", 3, 40, 4},
	{3, "E3", 3, 42, 0},
	{14, "E14", 4, 39, 0},
	{4, "E4", 5, 42, 3},
	{5, "E5", 3, 26, 0},
	{6, "E6", 5, 22, 0},
	{7, "E7", 4, 20, 0},
	{8, "E8", 4, 30, 0},
	{9, "E9", 5, 20, 2},
	{10,"E10", 2, 22, 0},
	{11, "E11", 3, 21, 0},
	{12, "E12", 3, 10, 0},
	{13, "E13", 3, 12, 0}	};

struct emp_info {
	int emp_id;
	char name[100];
	int rating;
	long salary;
	int reports;
};

struct treenode;

struct listnode {
	struct treenode *child;
	struct listnode *next;
};

struct treenode {
	struct emp_info info;
	struct listnode *child_list;
};

	

struct treenode * get_treenode(int i) {
	struct treenode * node = (struct treenode *) malloc(sizeof(struct treenode));
	node->info = emp[i];
	node->child_list = NULL;
	return node;
}

struct treenode * make_tree() {
	int index;
	struct treenode * root, *cur;
	cur = root = NULL;
	struct listnode *cur_child;

	if(root == NULL) {
		cur = root = get_treenode(i);
	}

	cur_child = cur->child_list;
	int children;
	children = cur->info.reports;

	while(children > 0) {
		getlistnode(index++);	
		children--;
	}
}

void main() {

	
	struct treenode *root = make_tree();


}

