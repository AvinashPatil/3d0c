/* Program to calculate the maximum distance from root to a node in graph with no cycles.

 1. We do a BFS from starting from root of graph.
 2. During BFS we also store the distance of a node from root.
 3. If a node is already visited but still has more distance from incoming node then update its distance
	and add it to queue again. 
 4, When the BFS is complete then visit all nodes and calculate the max distance.

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#define NODES 5

struct ListNode {
	int dest;
	struct ListNode *next;
};

struct AdjList {
	struct Listnode *head;
	int dist; // This field stores the max distance from root to itself.
};

struct Graph {
	int V;
	struct  AdjList *list;  // This is used as pointer to array of struct AdjList
};

struct Graph * create_graph(int V) {
	
	struct Graph *graph = (struct Graph *) malloc(sizeof(struct Graph));

	graph->V = V;
	graph->list = (struct AdjList *) malloc(sizeof(struct AdjList) * V);

	for(int i=0; i<V; i++) {
		graph->list[i].head = NULL;
		graph->list[i].dist = 0;
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

void BFS(struct Graph *graph, int v, bool visited[]) {

	struct queue *Q	= create_queue();
	int parent_dist;
	
	push_back(Q, v);

	while(!isEmpty(Q)) {
		v = pop_front(Q);
		parent_dist = graph->list[v].dist;
		visited[v] = true;
		
		// visit neighbours
		struct ListNode *node = graph->list[v].head;
		
		while(node) {
			if(visited[node->dest] == false || graph->list[node->dest].dist < parent_dist + 1) {
				graph->list[node->dest].dist = parent_dist + 1;	
				push_back(Q, node->dest);
			}
			node = node->next;
		}
	}
}


int calc_max(struct Graph *graph) {
	int max_dist = INT_MIN;
	for(int i=0; i<graph->V; i++) {
		printf("distance upto node %d is %d\n", i, graph->list[i].dist);
		if(max_dist < graph->list[i].dist) {
			max_dist = graph->list[i].dist;
		}
	}
	return max_dist;
}

int get_max_dist(struct Graph *graph, int v) {
	
	bool visited[graph->V]; 

	for(int i=0; i<graph->V; i++) {
		visited[i] = false;
	}
	
	BFS(graph, v, visited);
	return calc_max(graph);	
}

void main() {

	int V = NODES;

	struct Graph *graph = create_graph(V);

	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 1, 3);
	add_edge(graph, 2, 3);
	//add_edge(graph, 2, 4);
	add_edge(graph, 4, 2);
	add_edge(graph, 3, 4);

	print_graph(graph);

	int res = get_max_dist(graph, 0); // get the max distace from root i.e. 0
	printf("The maximum distance from root is %d\n",res);
}
