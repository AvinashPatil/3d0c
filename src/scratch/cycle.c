#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
	int dest;
	struct ListnNode *next;
};

struct AdjList {
	struct ListNode *head;
};

struct graph {
	int V;
	struct AdjList *list; 
};


struct graph * create_graph(int V) {

	struct graph *G = (struct graph *) malloc(sizeof(struct graph));
	G->V = V;
	G->list = (struct AdjList *) malloc(sizeof(struct AdjList) * V);

	for(int i=0; i<V; i++) {
		G->list[i].head = NULL;
	}
	return G;
}

void add_edge(struct graph *G, int src, int dest) {

	struct ListNode *node =  (struct ListNode *) malloc(sizeof(struct ListNode));
	node->dest = dest;
	if(G->list[src].head == NULL) {
		G->list[src].head = node;
		return;
	}
	node->next = G->list[src].head;
	G->list[src].head = node;
	return;
}


bool dfs(struct graph *G, int v, bool visited[], bool rec_stack[]) {

	visited[v] = true;
	rec_stack[v] = true;
	
	struct ListNode *node = G->list[v].head;
	
	while(node != NULL) {

		if(visited[node->dest] == false) {
			if(dfs(G, node->dest, visited, rec_stack) == true) {
				return true;
			}
		} else if(rec_stack[node->dest] == true) {
			return true;
		}

		node = node->next;
	}
	rec_stack[v] = false;
	return false;
}


bool detect_cycle(struct graph *G) {
	bool visited[G->V];
	bool rec_stack[G->V];
	for(int i=0; i<G->V; i++) {
		visited[i] = false;
		rec_stack[i] = false;
	}

	for(int i=0; i<G->V; i++) {
		if(visited[i] == false) {
			if(dfs(G, i, visited, rec_stack) == true) {
				return true;
			}
		}
	}
	return false;
}

void main() {

	struct graph *G = create_graph(5);
	
	add_edge(G, 1, 3);
	add_edge(G, 1, 5);
	add_edge(G, 2, 3);
	add_edge(G, 4, 5);
	add_edge(G, 5, 2);
	add_edge(G, 2, 1);

	if(detect_cycle(G)) {
		printf("Cycle present");
	} else {
		printf("Cycle not present");
	}
}
