/* Adjacency list representatio of a graph */


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>


struct ListNode {
	int dest;
	struct ListNode *next;
};

struct AdjList {
	struct Listnode *head;
};

struct Graph {
	int V;
	struct AdjList *list;  // This is used as pointer to array of struct AdjList
};

struct Graph * create_graph(int V) {
	
	struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph)); 

	graph->V = V;
	graph->list = (struct AdjList *) malloc(sizeof(struct AdjList) * V);

	for(int i=0; i<V; i++) {

		graph->list[i].head = NULL;
	}
	
	return graph;
}

void add_edge(struct Graph *graph, int u, int v) {
	
	struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
	node->dest = v;

	node->next = graph->list[u].head;
	graph->list[u].head = node;
}

void print_graph(struct Graph *graph) {
	for(int i=0; i < graph->V; i++) {
		struct ListNode *node = graph->list[i].head;
		while(node) {
			printf("Edge from node %d  to %d \n", i, node->dest);
			node = node->next;
		}
	}
}

void DFS_util(struct Graph *graph, int v, bool visited[]) {
	
	visited[v] = true;

	printf("Visited node %d \n", v);

	// Enlighten neighbours

	struct ListNode *node = graph->list[v].head;

	while(node) {
		if(visited[node->dest] == false) {
			DFS_util(graph, node->dest, visited);
		}
		node = node->next;
	}
}


void DFS(struct Graph *graph, int v) {
	
	bool visited[graph->V];

	for(int i=0; i<graph->V; i++) {
		visited[i] = false;
	}
	
	DFS_util(graph, v, visited);
}


#define MAX 100
struct queue {
	int front, rear;
	int item[MAX];
};

struct queue * create_queue() {
	struct queue *Q = malloc(sizeof(struct queue));
	Q->front = 0;
	Q->rear  = 0; 
	return Q;
}

void push_back(struct queue *Q, int i) {
	Q->item[Q->front] = i;
	Q->front++;
}	

int pop_front(struct queue *Q) {
	int temp;
	temp = Q->item[Q->rear];
	Q->rear++;
	return temp;
}	

bool isEmpty(struct queue *Q) {
	return (Q->rear == Q->front);
}

void BFS_util(struct Graph *graph, int v, bool visited[]) {

	struct queue *Q	= create_queue();
	
	push_back(Q, v);

	while(!isEmpty(Q)) {
		v = pop_front(Q);
		visited[v] = true;
		printf("Visited node %d \n", v);

		// Enlighten neighbours
		struct ListNode *node = graph->list[v].head;
		while(node) {
			if(visited[node->dest] == false) {
				push_back(Q, node->dest);
			}
			node = node->next;
		}
	}
}


void BFS(struct Graph *graph, int v) {
	
	bool visited[graph->V]; 

	for(int i=0; i<graph->V; i++) {
		visited[i] = false;
	}
	
	BFS_util(graph, v, visited);
}

void main() {

	int V = 5;

	struct Graph *graph = create_graph(V);

	add_edge(graph, 0, 1);
	add_edge(graph, 0, 4);
	add_edge(graph, 1, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 1, 4);
	add_edge(graph, 2, 3);
	add_edge(graph, 3, 4);

	print_graph(graph);

	DFS(graph, 0); // do DFS starting from node 0
	BFS(graph, 0); // do BFS starting from node 0

}

