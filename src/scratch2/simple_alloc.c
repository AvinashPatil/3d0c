#include<stdio.h>
#include<stdlib.h>

struct listnode{
	int size;
	void *addr;
	struct listnode *next;
};

struct freelist {
	int remaining;
	struct node *head;
};

struct freelist *g_freelist;

init_freelist(int size) {

	g_freelist = malloc(sizeof(struct freelist));

	struct listnode *node = (struct listnode *) malloc(sizeof(struct node));
	node->size = size;
	node->addr = (void *)malloc(size);
	node->next = NULL;

	g_freelist->head = node;
	g_freelist->remaining = size;
	
	

};

void init_myalloc(int size) {
	init_freelist(size);

}


void main() {
	init_myalloc(100);
	int *addr1 = my_alloc(5);
	int *addr2 = my_alloc(3);
	int *addr3 = my_alloc(25);
	
	int *addr4 = my_alloc(25);
	int *addr5 = my_alloc(25);
	my_free(addr4);
	destroy_myalloc();
de
}

