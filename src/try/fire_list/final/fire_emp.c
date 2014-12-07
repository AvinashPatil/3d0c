#include "data.h"
int get_rating(struct ListNode *, struct Graph *);
swap(struct ListNode *, struct ListNode *);

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

	struct ListNode * temp = node;

	while(temp->next && (get_rating(temp->next, graph) < get_rating(temp, graph))) {
		swap(temp->next, temp);
		temp = temp->next;
	}
	
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
