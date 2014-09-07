/* Prims algo for minimum spanning tree.

Make two sets MST and non-MST
Include nodes to MST one by one picking edges with minimum weight aringsing from vertices in MST

*/

#include<stdio.h>
#include<stdbool.h>
#include<limits.h>	
#define V 5


void print_sol(int parent[], int weight[]) {
	
	for(int i=0; i<V; i++) {
		printf("Edge %d-%d with weight %d \n", parent[i], i, weight[i]);
	}	
}


int get_min(int weight[], bool mst[]) {
	int min_weight = INT_MAX;
	int min_vertex;
	
	for(int i=0; i<V; i++) {
		if(mst[i] == false && weight[i] < min_weight) {
			min_weight = weight[i];
			min_vertex = i;
		}
	}
	return min_vertex;
}

void prims(int graph[][V]) {

	bool mst[V];
	int parent[V];
	int weight[V];



	// initialization
	for(int i=0; i<V ; i++) {
		mst[i] = false;
		weight[i] = INT_MAX;
	}

	// include 0 th node 
	weight[0] = 0;
	parent[0] = -1; // root is always the start

	for(int count=0; count<V; count++) {
		
		// get the vertex with minimum edge weight
		int u = get_min(weight, mst);
		
		// include this node in the set
		mst[u] = true;

		// enlighten the neighbours
		for(int v=0; v<V; v++) {

			if(mst[v] == false &&  // if this neighbour is not in the set
				graph[u][v] > 0 && // if this is adjacent 
				weight[v] > graph[u][v]) // if this neighbour is closer when we see through u
				{
					// well it satisfies all criterion
					// enlighten it
					parent[v] = u;
					weight[v] = graph[u][v];
				}
		}
	}

	print_sol(parent, weight);
}

void main() {

	int graph[V][V] = 
		     {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

	prims(graph);	
}

