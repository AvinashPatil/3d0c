/* Find the next greater element for each array element */

#include<stdio.h>
#include<stdbool.h>
#define MAX 100

struct stack {
	int top; 
	int item[MAX]; 
};

void initialize(struct stack *S) {
	S->top = -1;
	for(int i=0; i<MAX; i++) {
		S->item[i] = 0;
	}
}

void push(struct stack *S, int i) {
	S->top++;
	S->item[S->top] = i;
	return;
}

int pop(struct stack *S) {
	int ret = S->item[S->top];
	S->top--;
	return ret;
}

bool isEmpty(struct stack *S) {
	return (S->top == -1);
}

void next_greater(int a[], int len) {
	struct stack S;
	initialize(&S);
	int greater[len];

	for(int i=len-1; i >=0; i--) {
		if(!isEmpty(&S)) {
			if(a[i] < S.item[S.top]) {
				greater[i] = S.item[S.top];
			} else {
				while(a[i]>S.item[S.top]) {
					int temp = pop(&S);
				}
			}
		}

		if(isEmpty(&S)) {
			greater[i] = -1;
			push(&S, a[i]);
		} else {
			greater[i] = S.item[S.top];
			push(&S, a[i]);
		}
	}
	for(int i=0; i<len; i++) {
		printf(" %d --> %d", a[i], greater[i]);
	}
}
void main() {
	int a[] = {4, 5, 2, 25};
	int len = sizeof(a)/sizeof(a[0]);

	next_greater(a, len);
}
