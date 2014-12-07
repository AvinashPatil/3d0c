#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct listnode {
	int data;
	struct listnode *next;
};


struct listnode * getnode(int i) {
	struct listnode * node = (struct listnode *) malloc(sizeof(struct listnode));
	node->data = i;
	node->next = NULL;
	return node;
}


void insert(struct listnode **head, struct listnode *node) {
	if(*head == NULL) {
		*head = node;
		return;
	}
	node->next = *head;
	*head = node;
	return;
}

void reverse(struct listnode **head) {

	struct listnode *prev, *next, *cur;

	prev = NULL;
	cur = *head;

	while (cur) {
		next = cur->next;
		cur->next = prev; 
		prev = cur;
		cur = next;
	}
 	*head = prev;	
}

void printlist(struct listnode *head) {

	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
}

void main() {

	struct listnode *head = NULL;
	insert(&head, getnode(1));
	insert(&head, getnode(2));
	insert(&head, getnode(3));
	insert(&head, getnode(4));
	insert(&head, getnode(5));
	insert(&head, getnode(6));
	insert(&head, getnode(7));
	printlist(head);
	reverse(&head);
	//printlist(head);
}
