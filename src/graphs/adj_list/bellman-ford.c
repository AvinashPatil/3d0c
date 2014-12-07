#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct ListNode {
	int dest;
	int weight;
	struct ListNode *next;
};

struct AdjList {
	struct ListNode *head;

};

struct Graph {
	int V;
	struct AdjList *list;
};

struct Graph * create_graph(int V) {

	struct Graph *graph = (struct Graph *) malloc (sizeof(struct Graph));
	
	graph->V = V;

	graph->list = (struct AdjList *)malloc(sizeof(struct AdjList) *V);

	for(int i=0; i<V; i++) {
		graph->list[i].head = NULL;
	}
	return graph;
}

void add_edge(struct Graph *graph, int u, int v, int weight) {
	struct ListNode *edge= (struct ListNode *) malloc (sizeof(struct ListNode)); 

	edge->dest = v;
	edge->weight = weight; 

	edge->next = graph->list[u].head;
	graph->list[u].head = edge;
	
	return;
}


void print_sol(int dist[], int V, int v) {
	for(int i=0; i<V; i++) {
		printf("Distance of vertex %d is from srource %d is %d \n", i, v, dist[i]);
	}
}

void bellman_ford(struct Graph *graph, int v) {

	int V = graph->V;
	int dist[V];

	for(int i=0; i<graph->V; i++) {
		dist[i] = INT_MAX;
	}

	dist[v]= 0;

	for(int u= 0; u<V; u++) {
		struct ListNode * edge = graph->list[u].head;
	
		while(edge) {
			if(dist[edge->dest] > dist[u] + edge->weight) {
				dist[edge->dest] = dist[u] + edge->weight;
			}
			edge= edge->next;
		}
	}

	for(int u= 0; u<V; u++) {
		struct ListNode * edge = graph->list[u].head;
	
		while(edge) {
			if(dist[edge->dest] > dist[u] + edge->weight) {
				printf("There is a -ve weight cycle\n");
			}
			edge= edge->next;
		}
	}


	

	print_sol(dist, V, v );
}

void main() {
	int V = 5;
	struct Graph *graph = create_graph(V);

	add_edge(graph, 0, 1, -1);
	add_edge(graph, 0, 2, 4);
	add_edge(graph, 1, 2, 3);
	add_edge(graph, 1, 3, 2);
	add_edge(graph, 1, 4, 2);
	add_edge(graph, 3, 2, 5);
	add_edge(graph, 3, 1, 1);
	add_edge(graph, 4, 3, -3);

	
	bellman_ford(graph, 0); // find shortest distances to all othe vertices from 0
}




