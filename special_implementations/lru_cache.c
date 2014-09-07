/* Implement LRU cache 

1. A linked list for maitaining cache.
2. A hash table for for referencing page

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct page {
	struct page *next;
	struct page *prev;
	int page_number;
};

struct cache {
	struct page *head;
	struct page *tail;
	int capacity;
	int pages;
};

struct hash {
	struct page *ref[10];
};

struct page * getpage(int num) {
	struct page *p = (struct page *) malloc(sizeof(struct page));
	p->next = NULL;
	p->prev = NULL;	
	p->page_number = num;
	return p;
}


struct cache * init_cache(int capacity) {
	struct cache *c = (struct cache *) malloc(sizeof(struct cache));
	c->head = NULL;
	c->tail = NULL;
	c->capacity = capacity;	
	c->pages = 0;
	return c;
}

bool isFull(struct cache *c) {
	return (c->capacity == c->pages);
}
bool isEmpty(struct cache *c) {
	return (c->pages == 0);
}

int dequeue(struct cache *c) {

	int ret;
	if(isEmpty(c)) {
		return -1;
	}

	if(c->tail)
		ret = c->tail->page_number;
	if(c->head == c->tail) {
		free(c->tail);
		c->head = c->tail = NULL;
		return ret;
	}

	c->tail = c->tail->prev;
	free(c->tail->next);
	c->tail->next = NULL;
	return ret;
}

void enqueue(struct cache *c, struct hash *h,  struct page *p) {

	if(isEmpty(c)) {
		c->head = c->tail = p;
		return;
	}
	if(isFull(c)) {
		int temp = dequeue(c);
		h->ref[temp] = NULL;
		
	}
	p->next = c->head;
	p->next->prev = p;
	c->head = p;
	return;
}

void get_front(struct cache *c, struct page *p) {

	if (c->head == p) {
		// already at front
		return;
	}
	
	if(c->tail == p) {
		c->tail = p->prev;
	}

	if(p->prev)
		p->prev->next = p->next;
	if(p->next)
		p->next->prev = p->prev;
	
	p->next = c->head;
	p->prev = NULL;

	if(p->next)
		p->next->prev = p;
	c->head = p;
}

void reference(struct hash *h, struct cache *c, int page) {

	if(h->ref[page] == NULL) {
		h->ref[page] = getpage(page);
		enqueue(c, h, h->ref[page]);
		printf("Cache miss  for %d\n", page);
		return;
	} else {
		get_front(c, h->ref[page]);
		printf("Cache hit for %d\n", page);
	}
}

struct hash * init_hash() {

	struct hash *h = (struct hash *) malloc(sizeof(struct hash));
	for(int i=0; i<10; i++) {
		h->ref[i] = NULL;
	}
	return h;
}

void main() {
	struct cache *c = init_cache(4);
	struct hash *h = init_hash();

	reference(h, c, 4);
	reference(h, c, 5);
	reference(h, c, 1);
	reference(h, c, 4);
	reference(h, c, 6);
	reference(h, c, 3);
}
