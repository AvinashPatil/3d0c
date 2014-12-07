/*
http://community.topcoder.com/stat?c=problem_statement&pm=12615
*/


#include<stdio.h>


void print_seq(int seq[], int len) {
	printf("len = %d \n", len);
	for(int i=0; i<len; i++) {
		printf("%d ", seq[i]);
	}
	printf("\n");
}

static int count = -1;	
void  similar_seq(int seq[], int new_seq[], int bound, int len, int pos) {

	for(int i=1; i<=bound; i++) {
		for(int j= 0; j<len; j++) {
			count++;	
		}
	}

}

void main() {

	int seq[] = 
{1, 2, 3, 4, 5};
//{1, 2};
	int bound = 5;

//2;
	int len = sizeof(seq)/ sizeof(seq[0]);

	printf("len = %d\n", len);

	int new_seq[len];

	for(int i=0; i<len; i++) {
		new_seq[i] = seq[i];
	}

	//printf("Number of similar seq  are %d", similar_seq(seq, new_seq, bound, len,  0, 0));
	similar_seq(seq, new_seq, bound, len,  0);
	printf("Number of similar seq  are %d", count);
}
