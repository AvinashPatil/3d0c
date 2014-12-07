/*
Given sorted list of words find the precedence of characters in alien language.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define min(a,b) ((a<b)?a:b)
#define MAX 100


struct listnode {
	int dest;
	struct listnode *next;
};	

struct Adjlist {
	struct listnode *head;
};

struct graph {
	int V;
	struct Adjlist *array;
};

struct graph * create_graph(int V) {

	struct graph *G = (struct graph *)malloc(sizeof(struct graph));
	G->V = V;
	G->array = (struct Adjlist *) malloc(sizeof(struct Adjlist) * V); 
	for(int i=0; i<V; i++) {
		G->array[i].head = NULL;
	}
	return G;
}	

void add_edge( struct graph *G, int src, int dest) {
	struct listnode *node = (struct listnode *) malloc(sizeof(struct listnode));
	node->dest = dest;
	node->next = G->array[src].head;
	G->array[src].head = node;
	return;
}

struct stack {
	int top;
	int item[MAX];
};

void initialize(struct stack *S) {
	S->top = -1;
	for(int i=0; i<MAX; i++) {
		S->item[i] = 0;
	}
	return;
}

void push(struct stack *S, int i) {
	S->top++;
	S->item[S->top] = i;
	return;
}	

bool isEmpty(struct stack *S) {
	return (S->top == -1);
}

int pop(struct stack *S) {
	if(!isEmpty(S)) {
		int ret = S->item[S->top];
		S->top--;	
		return ret;
	}
}

void dfs(struct graph *G, int i, struct stack *S, bool visited[]) {

	visited[i] = true;
	struct listnode *node = G->array[i].head;
	while(node) {
		if(visited[node->dest] == false) {
			dfs(G, node->dest, S, visited);
		}
		node = node->next;
	}
	push(S, i);
}

void topological(struct graph *G) {
	bool visited[G->V];
	struct stack S;
	initialize(&S);
	for(int i=0; i<G->V; i++) {
		visited[i] = false;
	}
	for(int i=0; i<G->V; i++) {
		if(visited[i] == false) {
			dfs(G, i, &S, visited);
		}
	}
	while(!isEmpty(&S)) {
		printf("%c ", 'a' + pop(&S));
	}
}


void print_order(char *words[], int len, int chars) {

	struct graph *G = create_graph(chars);

	for(int i=0; i<len-1; i++) {
		for(int j=0; j<min(strlen(words[i]), strlen(words[i+1])); j++) {
			if(words[i][j] !=  words[i+1][j]) {
			//	printf("Add edge\n");
				add_edge(G, words[i][j] - 'a', words[i+1][j] - 'a');
				break;
			}
		}
	}
	topological(G);
}

void main() {
	char *words[] = {"caa", "aaa", "aab"};

	int len = sizeof(words)/sizeof(words[0]);
	print_order(words, len, 3);
}
