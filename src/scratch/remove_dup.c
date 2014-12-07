#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct list {
	struct list *next;
	int data;
};

struct list * getnode(int i) {
	struct list *node = (struct list *) malloc(sizeof(struct list));
	node->next = NULL;
	node->data = i;
}

void remove_dup(struct list **head) {
	struct list *prev = NULL;
	if((*head)->next == NULL) {
		return;
	}
	struct list *cur = (*head)->next;
	prev = *head;

	while(cur != NULL) {
		struct list *runner = *head;
		while(runner !=  cur) {
			if(runner->data == cur->data) {
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
				continue;
			}
			runner = runner->next;
		}
		prev = cur;
		cur = cur->next;
	}
	
	return;
	
}



void print(struct list *head) {
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
}
void main() {
	struct list *head = getnode(2);
	head->next = getnode(3);
	head->next->next = getnode(4);
	head->next->next->next = getnode(2);
	head->next->next->next->next = getnode(5);
	head->next->next->next->next->next = getnode(6);

	print(head);
	printf("\n");	
	remove_dup(&head);
	print(head);
}

