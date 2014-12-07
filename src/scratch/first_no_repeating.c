/* Find the first non repeating character in a stream in O(1) time
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define CHARS 26

struct listnode {
	char data;
	struct listnode *prev;
	struct listnode *next;
};

struct listnode * getnode(char c) {
	struct listnode *node = (struct listnode *) malloc(sizeof(struct listnode ));
	node->prev = NULL;
	node->next = NULL;
	node->data = c;
	return node;
}	

void insert(struct listnode **head, struct listnode **tail, struct listnode *node) {
	if(*head ==  NULL && *tail == NULL) {
		*head = node;
		*tail = node;
		return;
	}
	node->next = *head;
	(*head)->prev = node;
	*head = node;
	return;
}

void remove_node(struct listnode **head, struct listnode **tail, struct listnode *node) {

	if(*head == node && *tail == node) {
		*head = NULL;
		*tail = NULL;
		free(node);
		return;
	}

	if(*head == node) {
		*head = node->next;
		(*head)->prev = NULL;
	} 

	if(*tail == node ) {
		*tail = node->prev;
		(*tail)->next = NULL;
	}

	if(node->prev)
		node->prev->next = node->next;
	if(node->next)
		node->next->prev = node->prev;
	free(node);
}

void first_non_repeat() {

	bool repeat[CHARS] = {false};
	struct listnode *array[CHARS] = {NULL};

	for(int i=0; i<CHARS; i++) {
		repeat[i] = false;
		array[i] = NULL;
	}

	char stream[] = "geeksforgeeksandgeeksquizfor";
	struct listnode *head = NULL;
	struct listnode *tail = NULL;
	

	for(int i=0; i<strlen(stream); i++) {
		if(repeat[stream[i]] == false) {
			if(array[stream[i]] != NULL) {
				repeat[stream[i]] = true;
				array[stream[i]] = NULL;
				remove_node(&head, &tail, array[stream[i]]);
			} else {
				array[stream[i]] = getnode(stream[i]);
				insert(&head, &tail, array[stream[i]]);
			}
		}
	}
	printf("First non repeat is %c", head->data);
}


void main() {
	first_non_repeat();
}
