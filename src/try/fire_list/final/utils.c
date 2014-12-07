#include "data.h"




int get_rating(struct ListNode *child, struct Graph *graph) {

        return graph->list[child->dest].emp.rating;

}

void swap(struct ListNode *a, struct ListNode *b) {
        int temp = a->dest;
        a->dest = b->dest;
        b->dest = temp;
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


void print_graph(struct Graph *graph) {
        for(int i=0; i < graph->V; i++) {
                struct ListNode *node = graph->list[i].head;
                while(node) {
                        printf("Edge from node %d  to %d  with rating %d \n", i, node->dest, get_rating(node, graph));
                        node = node->next;
                }
        }
}
