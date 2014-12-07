/* Find the most frequent k words ina file
1. Read the word one by one and insert in a trie.
2. At the leaf node of trie maintain the frequency of word
3. If the frequency of word is more than top of min heap then remove word from heap and insert the new word in heap.
4. In the last return the words in heap.
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100
#define CHARS 26
#define K 100 

struct trienode {
	struct trienode *child[CHARS];
	bool isEnd;
	int freq;
	char word[SIZE];
};

struct heap {
	int freq;
	char *word;
};

struct trienode * getnode() {
	struct trienode *node = (struct trienode *) malloc(sizeof(struct trienode)); 
	node->isEnd = false;
	node->freq = 0;
	node->word[0] = '\0';
	for(int i=0; i<CHARS; i++) {
		node->child[i] = NULL;
	}
	return node;
}

char * extract_heap(struct heap h[], int *h_size) {

	char *ret= NULL;
	strcpy(ret, h[1].word);
	
	h[1] = h[*h_size];
	*h_size = *h_size - 1;
	if(*h_size < 0) {
		printf("\nsize is smaller\n");
	}
	
	int c;
	int i = 1;
	
	while(true) {
		c = 2*i;
		if(h[c].freq < h[c+1].freq) {
			c = c+1;
		}

		if(c > *h_size) {
			break;
		}
		if(h[c].freq < h[i].freq) {
			//swap
			struct heap temp = h[c];
			h[c] = h[i];
			h[i] = temp;
		} else {
			break;
		}
		i=c;
	}
	return ret;
}

void insert_heap(struct heap h[], int *h_size, int freq, char *word) {

	if(*h_size > K +1) {
		printf("\nsize bigger \n");
		return;
	}	 
	*h_size = *h_size+1;

	h[*h_size].freq =  freq;
	h[*h_size].word = word;
	
	int p;
	int i = *h_size;

	while(true) {
		p = i/2;
		if(p<1) {
			break;
		}
		if(h[p].freq > h[i].freq) {
			//swap
			struct heap temp = h[p];
			h[p] = h[i];
			h[i] = temp;
		} else {
			break;
		}

		i=p;
	}
	return;
}

void insert_trie(struct trienode **root, char buf[], char orig[], struct heap h[], int *h_size) {

	if(*root == NULL) {
		*root = getnode();
	}
	if(buf[0] == '\0') {
		(*root)->isEnd = true;
		(*root)->freq++;
		strcpy((*root)->word, orig);
		if((*root)->freq > h[1].freq) {
			if(*h_size >=K) {
				extract_heap(h, h_size);
			}
			insert_heap(h, h_size, (*root)->freq, (*root)->word);
		}
		return;
	} else {
		char c = buf[0];
		int index = 0;
		if(c >= 'a' &&  c <= 'z') {
		 	index = buf[0] - 'a';
		}
		if(c >= 'A' && c<= 'Z') {
		 	index = buf[0] - 'A';
		}
		insert_trie(&(*root)->child[index], buf+1, orig, h, h_size);
	}
	return;
}

void init_heap(struct heap h[]) {
	for(int i=0; i<K; i++) {
		h[i].freq = 0;
		h[i].word = NULL;
	}
}

void main() {

	FILE *fd = fopen("file.txt", "r");
	char buf[SIZE];
	struct trienode *root = NULL;
	struct heap h[K+1];
	init_heap(h);
	int h_size = 0;

	while(fscanf(fd, "%s", buf) != EOF) {
		insert_trie(&root, buf, buf, h, &h_size);
	}

	int i= 5;

	while(i--) {
		printf("\nMost frequent word is %s\n", extract_heap(h, &h_size));

	}

	fclose(fd);
}

