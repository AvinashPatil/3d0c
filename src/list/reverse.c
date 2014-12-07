#include<stdio.h>
#include<stdlib.h>

struct listnode {
	int data;
	struct listnode *next;
};

struct listnode * getnode(int i) {
	struct listnode *node = (struct listnode*) malloc(sizeof(struct listnode));
	node->data = i;
	node->next = NULL;
}

void add(struct listnode **head, struct listnode *node) {

	if(*head ==  NULL) {
		*head = node;
		return;
	}
	node->next = *head;
	*head = node;
	return;
}

void reverse(struct listnode **head) {
	struct listnode *next;
	struct listnode *prev = NULL;
	struct listnode *cur = *head;
	while(cur != NULL) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	*head = prev;
}	

struct listnode * pairwise_swap(struct listnode *head) {
	
	// never forget to add error cases
	if(head == NULL || head->next == NULL) {
		return head;
	}

	struct listnode *newhead;
	struct listnode *remaining;

	newhead = head->next;
	remaining = head->next->next;
	
	newhead->next = head;
	head->next = pairwise_swap(remaining);

	return  newhead;
}

void rotate(struct listnode **head, int k) {
	// rotate the linked list by k positions

	struct listnode *kth_node = NULL;
	struct listnode *kth_node_next = NULL;
	struct listnode *last_node = NULL;
	struct listnode *temp = *head;

	while(temp != NULL) {
		if(k== 0) {
			kth_node = temp;
			kth_node_next = temp->next;
		}
		if(temp->next == NULL) {
			last_node = temp;
		}
		temp = temp->next;
		k--;
	}
	kth_node->next = NULL;
	last_node->next = *head;
	*head = kth_node_next;
	
}

void segregate_even_odd(struct listnode **head) {
	
	struct listnode *tail = *head;
	struct listnode *odd = NULL;
	struct listnode *next;
	struct listnode *prev = NULL;

	while(tail != NULL) {

		if(tail->data & 1) {
			// make head safe
			if(tail == *head) {
				*head = tail->next;
			}
			// save tail for future
			next = tail->next;
			if(prev)
			prev->next = next;
			

			// add this item to odd list
			tail->next = odd;
			odd = tail;
			// continue the tail	
			prev = tail;
			tail = next;
			
		} else  {
			prev = tail;
			tail = tail->next;
		}
	}
	prev->next = odd;
}

int add_digit(struct listnode *head, int a) {
	if(head->next == NULL) {
		head->data += a;
		if(head->data > 9) {
			head->data %= 10;
			return 1;
		 } else {
			return 0;
		}
	}
	head->data += add_digit(head->next, a);
	if(head->data > 9) {
		head->data %= 10;
		return 1;
	} else {
		return 0;
	}
}

void print_list(struct listnode *head) {
	while(head != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void main() {
	struct listnode *head = NULL;
	add(&head, getnode(1));
	add(&head, getnode(2));
	add(&head, getnode(3));
	add(&head, getnode(4));
	add(&head, getnode(5));
	add(&head, getnode(6));
	print_list(head);
	reverse(&head);
	print_list(head);
	head = pairwise_swap(head);
	print_list(head);
	head = pairwise_swap(head);
	print_list(head);
	rotate(&head, 3);
	print_list(head);
	segregate_even_odd(&head);
	print_list(head);
	int a = add_digit(head, 9);
	print_list(head);
}
