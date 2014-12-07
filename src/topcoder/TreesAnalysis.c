/*
http://community.topcoder.com/stat?c=problem_statement&pm=13086
*/


#include<stdio.h>
#include <stdbool.h>
#define max(a,b) a>b?a:b

// do dfs of a tree without going to the other tree which is connected with start-avoid
// obtain a group g
void dfs(int t[], int start, bool g[], int avoid, int len) {

	// visit the root

	g[start] = true;


	// enlighten neighbours

	// there are two cases to find neighbours
	// 1. t[start] itself
	// 2. i where t[i] = start 
	if(t[start] < len && t[start] != avoid && g[t[start]] == false) {
		dfs(t, t[start], g, avoid, len);
	}	
	for(int i=0; i<len; i++) {
		if(t[i]== start && g[i] == false && i != avoid) {
			dfs(t, i, g, avoid, len);
		}
	}
}
// remove an edge e and t[e] and obtain two groups
void remove_edge(int t[], int e, bool g1[], bool g2[], int len) {

	dfs(t, e, g1, t[e], len);
	dfs(t, t[e], g2, e, len);
}
// how similar two groups are
// means how many vertices they have in common
int sim(bool g1[], bool g2[], int len) {
	int ret = 0;
	for(int i=0; i<len; i++) {
		if(g1[i] && g2[i])
			ret++;
	}
	return ret;
}

int compute_similarity(int t1[], int t2[],  int len) {
	bool g11[len], g12[len], g21[len], g22[len];
	int MAX = 0;
	int sum = 0;

	// remove each edge in the graphs with each eadge have one of the vertex as i
	// for each removed eadge each tree will be split in two parts
	// call them g11 and g12 for t1
	// and g21, g22 for t1
	// obtain these groups from remove_edge function
	// calculate similarity between each of the groups from differenr trees by function sim
	// get maximum of these sims and return it.

	for(int i=0; i<len; i++) {
		int sq = 0;

		for(int j=0; j<len; j++) {
			g11[j] = g12[j] = g21[j] = g22[j] = false;
		}

		remove_edge(t1, i, g11, g12, len);
		remove_edge(t2, i, g21, g22, len);
		//MAX = max(MAX,  max(max(sim(g11, g21, len), sim(g11, g22, len)), max(sim(g12, g21, len), sim(g12, g22, len))));
		sq =  max(max(sim(g11, g21, len), sim(g11, g22, len)), max(sim(g12, g21, len), sim(g12, g22, len)));
		sum = sum + (sq*sq);
	}
	//return MAX;
	return sum;	

	//return max(max(sim(g11, g21, len), sim(g11, g22, len)), max(sim(g12, g21, len), sim(g12, g22, len)));
}

void main() {

	int t1[] = 
	//{1};
	{2, 4, 1, 0};
	//{2, 3, 4, 4, 5, 8, 5, 6, 10, 8};

	int t2[] = 
	//{1};
{1, 4, 4, 4};
	//{9, 0, 1, 0, 3, 0, 5, 0, 7, 10};

	

	int len = sizeof(t1)/sizeof(t1[0]);




	int sim = compute_similarity(t1, t2, len);	

	printf("Simliarity is %d", sim);
}
