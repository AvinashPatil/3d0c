#include<stdio.h>

struct node {
	int data;
	struct node *prev;
	struct node *next;
};

struct list {
	struct node *top;
	struct node *mid;
	int elements;
};

void push(struct list *stack, int i) {
	struct node *item = (struct node) malloc(sizeof(struct node));
	item->data = i;
	if(stack->top == NULL && stack->elements == 0) {
		stack->top = item;
		stack->mid = item;
		item->next = NULL;
		item->prev = NULL;
		return;
	}

	item->next = stack->top;
	item->prev = NULL;
	stack->top->prev = item;
	stack->top = item;
	stack->capacity++;
	if(stack->capacity%2 != 0) {
		stack->mid = stack->mid->next;
	}
}

struct node * pop(struct list *stack) {
	if(stack->capaity == 0) {
		return NULL;
	}
	struct node *ret = stack->top;
	stack->top = stack->top->prev;

	if(stack->top) {
		stack->top->prev = NULL;
	}

	stack->capacity--;

	if(stack->capacity %2 == 0) {
		stack->mid = stack->mid->prev;
	}
}


void main() {
}
