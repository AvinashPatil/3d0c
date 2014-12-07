#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#define CHARS 26

struct trie {
	bool isEnd;
	struct trie *child[CHARS];
};

struct trie * getnode() {
	struct trie *node = (struct trie *) malloc(sizeof(struct trie));
	node->isEnd = false;
	for(int i=0; i<CHARS; i++) {
		node->child[i] = NULL;
	}
	return node;
}

void insert(struct trie **root, char str[]) {
	if(*root ==  NULL) {
		*root = getnode();
	} 
	if(str[0] == '\0') {
		(*root)->isEnd = true;
	} else {
		int index = str[0] - 'a';
		insert(&(*root)->child[index], str+1);
	}
}

int get_matching(struct trie *root, char str[]) {
	
	int count = 0;
	while(true) {
		int index = str[count] - 'a';
		if(root->isEnd == false && root->child[index]) {
			count++;
			root = root->child[index];
		} else {
			return count;
		}
	}
}

int longest_palindrome(struct trie *root, char str[]) {
	int max = INT_MIN;
	for(int i=strlen(str)-2; i>=0; i--) {
		int res = get_matching(root, str+i);
		if(res > max) {
			max = res;
		}
	}
	return max;
}	

void reverse(char str[]) {
	int start =0;
	int end = strlen(str)-1;
	while(start < end) {
		char temp;
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void print_trie(struct trie *root, char out[], int pos) {

	if(root->isEnd) {
		out[pos] = '\0';
		printf("\n%s \n", out);
		return;
		
	}

	for(int i=0; i<CHARS; i++) {

		if(root->child[i]) {
			out[pos] = 'a' + i;
			print_trie(root->child[i], out, pos+1);
		}
	}
}	

void main() {
	struct trie *root = getnode();
	char str[100] = "forgeeksskeegfor";
	for(int i=strlen(str)-1; i>=0; i--) {
		insert(&root, str+i);
	}
	char out[100];
	//print_trie(root, out, 0);
	reverse(str);
	printf("Longest palindromic substring len is %d", longest_palindrome(root, str));
}
