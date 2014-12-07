#include<stdio.h>
#include<stdlib.h>


struct listnode {
	int data;
	struct listnode *next;
};

void add_node(struct listnode **head, int i) {

	struct listnode *node = (struct listnode *) malloc(sizeof(struct listnode));
	node->next = *head;
	node->data = i;
	*head = node;
}

void printlist(struct listnode *head) {
	while(head) {
		printf("%d ", head->data);
		head = head->next;
	}
	return;
}

struct listnode * merge(struct listnode *a, struct listnode *b) {

	struct listnode *result = NULL;
	if(a == NULL) {
		return b;
	}
	if(b == NULL) {
		return a;
	}
	if(a->data < b->data) {
		result = a;
		result->next = merge(a->next, b);
	}
	if(b->data <= a->data) {
		result = b;
		result->next = merge(a, b->next);
	}
	return result;
}

void main() {
	struct listnode *head1, *head2;
	head1 = head2 = NULL;
	
	add_node(&head1, 9);
	add_node(&head1, 7);
	add_node(&head1, 5);
	add_node(&head1, 3);
	add_node(&head1, 1);
	add_node(&head2, 8);
	add_node(&head2, 6);
	add_node(&head2, 4);
	add_node(&head2, 2);
	add_node(&head2, 0);

	struct listnode *result = merge(head1, head2);
	printlist(result);
}
