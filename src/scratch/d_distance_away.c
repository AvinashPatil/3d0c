/* rearrange string such that repeating characters are d distance away.

Algorithm:

1. Build a heap based on frequency of char
2. extract maximum occuring element from heap.
3. Put it in first empty location.
4. Put its next occurrence at first+d positions away.
5. Rrepeat the above steps till the heap is empty.

*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define CHARS 26

struct heaps {
	char c;
	int freq;
};

void insert_heap(struct heaps heap[], char c, int freq, int *size) {
	*size = *size+1;
	heap[*size].c = c;
	heap[*size].freq = freq;

	int i = *size;
	int p;
	
	while(true) {
		p = i/2;
		if(p<=1) {
			break;
		}
		if(heap[p].freq < heap[i].freq) {
			struct heaps temp;
			temp = heap[p];
			heap[p] = heap[i];
			heap[i] = temp;
		} else {
			break;
		}
		i=p;
	}
}
int  extract_max(struct heaps heap[], int *size) {
	int ret = 1;

	heap[1] = heap[*size];
	*size = *size -1; 

	int c;
	int i = 1;
	while(true) {
		c = i*2;
		if(c>=*size) {
			break;
		} 
		if(heap[c].freq < heap[c+1].freq) {
			c = c+1;
		}
		if(heap[c].freq > heap[i].freq) {
			struct heaps temp;
			temp = heap[c];
			heap[c] = heap[i];
			heap[i] = temp;
		} else {
			break;
		}

		i = c;
	}
	return ret;
}

void rearrange(char str[], int len, int d) {
	struct heaps heap[CHARS] = {{0, 0}}; // initialize heap to 0
	int size = 1;
	int counts[CHARS] = {0};

	for(int i=0; i<len; i++) {
		counts[str[i] -'a']++;
	}
	for(int i=0; i<len; i++) {
		insert_heap(heap, str[i], counts[str[i]-'a'], &size);
	}
	for(int i=0; i<len; i++) {
		str[i] = '\0';
	}
	
	while(size >=1) {

		int temp = extract_max(heap, &size);
		int k;
		k=0;
		while(str[k] != '\0') {k++;};
		for(int i=0; i<heap[temp].freq; i++) {
			//printf(" %d %d %d \n",i , k, heap[temp].freq);
			str[k] = heap[temp].c;
			k = k+d;	
			while(str[k] != '\0') {k++;};
			if(k >= len) {
				printf("Can not rearrange\n");
				break;
			}
		}
	}
}

void main() {
	char str[] = "aabbcc";
	int len = strlen(str);
	rearrange(str, len, 1);

	printf("%s\n", str);
}
