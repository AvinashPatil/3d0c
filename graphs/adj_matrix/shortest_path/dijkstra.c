#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 9
#define INF INT_MAX

void print_solution(int dist[]) {

	for(int i=0; i<V; i++) {
		printf("Distance of vertex %d from vertex 0 is %d\n", i, dist[i]);
	}
}

int get_min_dist_vertex(int dist[], bool sp_set[]) {

	int min_dist = INT_MAX;
	int min_vertex;
	
	for(int i=0; i<V; i++) {
		if(sp_set[i] == false && dist[i] < min_dist) {
			min_dist = dist[i];
			min_vertex = i;
		}
	}
	return min_vertex;
}

void dijkstra(int graph[V][V]) {
	
	int dist[V];
	bool sp_set[V];

	for(int i=0; i<V; i++) {
		dist[i] = INT_MAX;  // initialize dis array as INF
		sp_set[i] = false;  // there is no vertx in the shortest path set
	}

	// Distance to source is 0
	dist[0] = 0;

	for(int count=0; count<V; count++) {
		
		// get a minimum distance vertex which is not yet picked.
		int u = get_min_dist_vertex(dist, sp_set);

		// include the verted in the sp_set

		sp_set[u] = true;

		// calculate the new distances to neighbours of all vertices included in the sp_set

		for(int v=0; v<V; v++) {
			if(sp_set[v] == false && // this vertex is not yet included in set sp_set
			      graph[u][v] > 0 &&  // there is edge from u to v
			      dist[v] > dist[u] + graph[u][v]) { // current dist of v from source is larger than distance through u	
				
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}
	print_solution(dist);
}


void main() {

	int graph[V][V] = 

	       	     {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

	dijkstra(graph);
}
