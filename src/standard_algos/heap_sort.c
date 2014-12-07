#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

// keep heap size as global
int size = 0;

void insert_heap(int a[],  int x) {
	// increment the size and copy new element to end of heap
	size = size + 1;
	a[size] = x;
	
	// Now shift the new element upwards 
	int i=size;
	int p;
	
	while(true) {
		if(i <= 1) {
			break;
		}

		p = i/2;

		if(a[p] > a[i]) {
			int t = a[p];
			a[p] = a[i];
			a[i] = t;
		} else {
			break;
		}

		i = p;
	}
}

int extract_min(int a[]) {
	
	// We always return the top element of heap	
	int ret=a[1];

	// Copy the last element to the first slot, reduce the size
	a[1] = a[size];
	size = size - 1;
	

	// Push down this element downwards
	int i = 1;
	int c;
	
	while(true) {
		
		c = 2 * i;
		if(c > size) {
			break;
		}

		// go to appropriate kid	
		if(a[c] > a[c+1]) {
			c = c+1;
		}

		if(a[c] < a[i]) {
			int t = a[c];
			a[c] = a[i];
			a[i] = t;
		} else {
			break;
		}

		i = c;
	}

	return ret;
}

void heap_sort(int a[], int len) {
	for(int i=1; i<len; i++) {
		insert_heap(a, a[i]);
	}
	for(int i=1; i<len; i++) {
		//printf("%d ", a[i]);
	}
	for(int i=1; i<len; i++) {
		printf("%d ", extract_min(a));
	}
	
}

void main() {
	int a[] = {INT_MAX, 3, 5, 8, 2, 9, 7, 1, 0};
	int len = sizeof(a)/sizeof(a[0]);
	
	heap_sort(a, len);
}
