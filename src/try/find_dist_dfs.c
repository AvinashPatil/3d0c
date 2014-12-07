/* Program to find the max distance from root
 1. This approach uses DFS to solve this problem. 
 2. In DFS we calculate the depath of recursion which is distance of a node from root.
 3. The modification to the DFS is to visit a node even if it is already visited and calculate the maximum path.
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

#define NODES 5

struct ListNode {
	int dest;
	struct ListNode *next;
	
};

struct AdjList {
	struct Listnode *head;	
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

int DFS_util(struct Graph *graph, int v, bool visited[], int depth) {
	
	static int max_depth = 0;
	visited[v] = true;

	printf("Visited node %d \n", v);

	if(depth > max_depth) {
		max_depth = depth;
	}

	// Enlighten neighbours

	struct ListNode *node = graph->list[v].head;

	while(node) {
		DFS_util(graph, node->dest, visited, depth+1);
		node = node->next;
	}
	return max_depth;
}


int DFS(struct Graph *graph, int v) {
	
	bool visited[graph->V]; 

	for(int i=0; i<graph->V; i++) {
		visited[i] = false;
	}
	
	return DFS_util(graph, v, visited, 0);
}

void main() {

	int V = NODES;

	struct Graph *graph = create_graph(V);

        add_edge(graph, 0, 1);
        add_edge(graph, 0, 2);
        add_edge(graph, 1, 3);
        add_edge(graph, 2, 3);
	add_edge(graph, 2, 4);
        add_edge(graph, 3, 4);
	
	print_graph(graph);

	int res = DFS(graph, 0); // do DFS starting from node 0

	printf("\nMax distance from root is %d\n", res);
}
