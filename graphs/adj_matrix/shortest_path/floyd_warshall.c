/* Program to find ALL PAIR SHORTEST PATHS using floyd warshall algorithm

Logic: This algorithm asks that what all paths go through 'k' whos distance can be minimized.
*/

#include<stdio.h>
#define V 4
#define INF 1000


void floyd_warshall(int graph[V][V]) {

	int dist[V][V];

	// copy graph to dist
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			dist[i][j] = graph[i][j];
		}
	}

	// Algo
	for(int k = 0; k<V; k++) {
		for(int i=0; i<V; i++) {
			for(int j=0; j<V; j++) {
				if(dist[i][j] > (dist[i][k] + dist[k][j])) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	// print solution 
	for(int i=0; i<V; i++) {
		for(int j=0; j<V; j++) {
			printf("%d ", dist[i][j]);
		}
		printf("\n");
	}

}
void main() {

	int graph[V][V] =
		      { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };

	floyd_warshall(graph);	
}

