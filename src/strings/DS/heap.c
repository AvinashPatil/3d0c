/* Program to arrange repeating characters d distance away in a string*/



#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define CHARS 256


int freq[CHARS]; // Array sto store freq of each char
struct heap_struct {
	char a;
	int freq;
}; // char and freq


void swap(struct heap_struct heap[], int i, int j) {
	struct heap_struct temp;
	temp = heap[i];
	heap[i] = heap[j];
	heap[j]	= temp;
}	

int build_heap(struct heap_struct heap[], int len, int freq[]) {

	// this heap starts from index 1 in array
	int index=0;
	int p;
	for(int f=0; f<CHARS; f++) {
		if(freq[f] > 0) {
			// little prep
			// pre HEAP(1,N-1)
			// post HEAP(1, N) 
			// insert the new element to the last position and do shiftup
			index++;
			int i = index; 	
			heap[i].a = f;
			heap[i].freq = freq[f]; 
			
			// shift up
			while(true) {
				if(i == 1) {
				 	break;		
				}
				p = i/2;
				if(heap[p].freq < heap[i].freq) {
					swap(heap, i, p);
				} else {
					break;
				}
				i = p;
			}
		}
	}
	return index;
}


struct heap_struct  extract_max(struct heap_struct heap[], int *size) {

	// prepare item to return
	struct heap_struct ret = heap[1];

	if (*size==1) {
		(*size)--;
		return ret;
	}

	// pre HEAP(2, N)
	//post HEAP(1,N-1)
	
	heap[1] = heap[*size];

	(*size)--;		

	int i = 1;
	int c;

	while(true) {
		c = 2*i;
		if(c > (*size)) {
			break;
		}
		if(heap[c+1].freq > heap[c].freq) {
			c = c+1;
		}
		if(heap[c].freq > heap[i].freq) {
			swap(heap, i, c);
		} else {
			break;
		}
		i = c;
	}
	return ret;
}

char * rearrange(char str[], int len, int distance) {

	char *ret = (char *) malloc(len);
	memset(ret, 0, len);

	int uniq = 0;

	// calculate the frequency

	for(int i=0; i<len; i++) {

		if(freq[str[i]] == 0) {
			uniq++;
		}

		freq[str[i]]++;
	}

	// build the heap
		
	struct heap_struct heap[uniq];
	memset(heap, 0, sizeof(struct heap_struct) * uniq);

	int size = build_heap(heap, uniq, freq);

	// extract from heap and rearrange

	int item_no = 0;
	while(size>0) {
		struct heap_struct item;	
		item = extract_max(heap, &size);
		//printf("item is %c %d  %d\n", item.a, item.freq, size);
		for(int i = 0, j=0; i<item.freq; i++) {
			while(ret[j] != '\0') {
				j++;
			}
			ret[j] = item.a;
			j = j + distance;
			printf("putting %c at %d \n", item.a, j);
		}
	}

	return ret;
}		

void main() {
	char str[] = "daabbcc";
	int len = strlen(str);

	printf(" String after rearrangement is %s", rearrange(str, len , 2));
}
