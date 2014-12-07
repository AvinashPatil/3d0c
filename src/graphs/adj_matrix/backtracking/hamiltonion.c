/* Program to find Hamiltonion path if there exists one.

HP - path which goes through all teh vertices and visists each vertex only once.

Learnings:

1. In Backtracking return when we find one sultion. Comments below.
2. Check for isSafe conditions. e.g. In HP we have to check if this vertex is not already visited.
3. Do not forget the preparation work before calling a function e.g. include 0th vertex in the path before calling hamiltonion routine.

*/ 


#include<stdio.h>
#include<stdbool.h>

#define V 5

// this function will tell if vertex i can be included at posotion pos in path
// two conditions we must check

// 1. If the vertex is already in path
// 2. If the vertex and previous vertex is connected.
bool isSafe(bool graph[][V], int path[], int pos, int i) {

	for(int k=0; k<pos; k++) {
		if(path[k] == i) {
			return false;
		}
	}
	
	if(graph[path[pos-1]][i] == 1) {
		return true;
	} else {
		return false;
	}
}

bool build_hamiltonion(bool graph[][V], int path[], int pos) {

	// base case
	// if pos==V the check if last vertex on the path is connected with the first vertex 

	if(pos == V) {
		if(graph[path[pos]][0] == 1) {
			return true;
		} else {
			return false;
		}
	}

	// recurse 
	// for each vertex if it can be added to current path

	for(int i=0; i<V; i++) {

		if(isSafe(graph, path, pos, i)) {

			path[pos] = i;

			if(build_hamiltonion(graph, path, pos+1)) {  // we have found one of the soluions and we are happy !! so return
				return true;
			}
				// but if we still dont have the solution we have to continue with life :(
		}
	}
	return false;
}

void print(int path[]) {
	for(int i= 0; i<V; i++) {
		printf(" %d", path[i]);
	}
}	


void hamiltonion(bool graph[][V]) {
	int path[V];
	
	// initialize path to -1
	for(int i=0; i<V; i++) {
		path[i] = -1;
	}

	// include the first vertex in the path
	path[0] = 0;

	// pass graph and path to function and build path	
	if(build_hamiltonion(graph, path, 1)) {
		print(path);
	} else {
		printf("Path does not exists\n");
	}
	
}

void main() {
	bool graph[V][V] = 
		     {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };	

	hamiltonion(graph);
}
