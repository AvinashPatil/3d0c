#include<stdio.h>
#define len 5
#define lists 4

struct heap{
	int item;
	int next_index;
	int list;
};

void merge(int a[][lists], int out[]) {

	struct heap[lists]; // declare a heap
	memset(heap, 0, sizeof(struct heap) *lists); //initialize

	// insert the first elements
	for(int i=0; i<lists; i++) {
		heap[i].item = a[i][0];
		heap[i].next_index = 1;
		heap[i].list = i; 	
	}

	heapify(heap, lists);

	for(int i=0; i<len*lists; i++) {
		// extract min	
		struct heap_node = extract_min(heap);

		// fill in the out list
		out[i] = heap_node.item;
		
		// prepare item to insert
		struct new_node;
		if(heap_node.next_index < len) {
			new_node.item = a[heap_node.list][heap_node.next_index];
		} else {
			new_node.item = INT_MAX;
		}
		new_node.next_index = heap_node.next_index+1;
		new_node.list = heap_node.list; 

		// insert newly created item
		heap_insert(heap, new_node);
	}
}


void main() {

	int a[lists][len] = {
				{1, 3, 5, 6, 5},
				{0, 7, 5, 3, 2},
				{4, 3, 2, 1, 9},
				{-1, 3, 6, 7, -6}
			};

	int out[len*lists];
	memset(out, 0, len*lists);
	merge(a, out);
	for(int i=0; i<len*lists; i++) {	
		printf("%d ",out[i]);
	}
}
