/* Adjacency list representatio of a graph */


#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define EMPLOYEES 14
#define MAX_NAME_LEN 100


struct emp_info {
        int emp_id;
        char name[MAX_NAME_LEN];
        int rating;
        long salary;
        int reports;
};

struct ListNode {
	int dest;
	struct ListNode *next;
};

struct AdjList {
	struct Listnode *head;	
	struct emp_info emp;
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

int get_rating(struct ListNode *child, struct Graph *graph) {

	return graph->list[child->dest].emp.rating;
	
}	

void swap(struct ListNode *a, struct ListNode *b) {
	int temp = a->dest;
	a->dest = b->dest;
	b->dest = temp;
}

void add_edge(struct Graph *graph, int u, int v) {
	
	struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
	node->dest = v;

	node->next = graph->list[u].head;
	graph->list[u].head = node;

	struct ListNode * temp = node;

	while(temp->next && (get_rating(temp->next, graph) < get_rating(temp, graph))) {
		swap(temp->next, temp);
		temp = temp->next;
	}
	
}

void set_emp_info(struct Graph *G) {


	struct emp_info emp[14] = {   {1, "E1", 4, 50, 4},
		{2, "E2", 3, 40, 4},
		{3, "E3", 3, 42, 0},
		{14, "E14", 4, 39, 0},
		{4, "E4", 5, 42, 3},
		{5, "E5", 3, 26, 0},
		{6, "E6", 5, 22, 0},
		{7, "E7", 4, 20, 0},
		{8, "E8", 4, 30, 0},
		{9, "E9", 5, 20, 2},
		{10,"E10", 2, 22, 0},
		{11, "E11", 3, 21, 0},
		{12, "E12", 3, 10, 0},
		{13, "E13", 3, 12, 0}   };


	for(int i=0; i<G->V; i++) {
		G->list[i].emp = emp[i]; 
	}
	return;
}


void set_heirarchy(struct Graph *graph) {
	add_edge(graph, 0, 1);
	add_edge(graph, 0, 2);
	add_edge(graph, 0, 3);
	add_edge(graph, 0, 4);

	add_edge(graph, 1, 5);
	add_edge(graph, 1, 6);
	add_edge(graph, 1, 7);
	add_edge(graph, 1, 8);

	
	add_edge(graph, 4, 9);
	add_edge(graph, 4, 10);
	add_edge(graph, 4, 11);

	add_edge(graph,  9, 12);
	add_edge(graph,  9, 13);
}

void print_graph(struct Graph *graph) {
	for(int i=0; i < graph->V; i++) {
		struct ListNode *node = graph->list[i].head;
		while(node) {
			printf("Edge from node %d  to %d  with rating %d \n", i, node->dest, get_rating(node, graph));
			node = node->next;
		}
	}
}


void get_fire_list(int emp_id, float percentage, struct Graph *graph) {

	int num = ceil(graph->list[emp_id -1].emp.reports * percentage);

	struct ListNode *node = graph->list[emp_id-1].head;
	for(int i=0; i<num; i++) {
		if(node) {
			printf("Fire emp id %d\n", node->dest+1);
		} else {
			break;
		}	
		node = node->next;
	}
	
	node = graph->list[emp_id-1].head;
	while(node) {
		get_fire_list(node->dest+1, percentage, graph);
		node = node->next;
	}
}

void main() {

	int V = EMPLOYEES;

	struct Graph *graph = create_graph(V);

	set_emp_info(graph);
	set_heirarchy(graph);

	//print_graph(graph);
	get_fire_list(1, 0.5, graph);

}
