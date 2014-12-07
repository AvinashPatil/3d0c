/* Program in which write stack such that it always return min element in O(1) time.

Learnings:
	1. Initialize top to -1
	2. Always increment top and then push on stack.
	3. Always decrement and then do the pop 	

Time taken:
	1. Create a function isempty
	2. In min function when stack is empty then return INT_MAX (limits.h) always.
 
*/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<limits.h>

#define MAX 100

struct stack {
	int top;
	int data[MAX];
};


struct stack M; // stack for storing min

void pushmin(int i) {

	M.top++;
	M.data[M.top] = i;
}
void popmin() {
	if(M.top >= 0)
		M.top--;
	else 
		printf("Error while popmin");
}

bool
isempty(struct stack *S){
	if(S->top == -1) {
		return true;
	}	
	return false;
}

int min() {
	if(isempty(&M)) {
		return INT_MAX;
	}
	return M.data[M.top];
}

void push(struct stack *S, int i) {
	if (i< min()) {
		pushmin(i);
	}
	S->top++;
	S->data[S->top] = i;
}

int pop(struct stack *S) {
	if(S->data[S->top] == min()) {
		popmin();
	}
	return(S->data[S->top--]);
}

void main() {

	int a[] = {4, 2, 1, 6, -3, 6, 7};
	struct stack S;
	memset(&S, 0, sizeof(struct stack));
	S.top = -1;
	M.top = -1;

	for(int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
		push(&S, a[i]);
		printf("Min elelent is %d  %d\n", min(), S.top );
	}
}

