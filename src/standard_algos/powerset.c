#include<stdio.h>


void print_powerset(int p[], int len) {
	for(int i=0; i<len; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}

void powerset(int a[], int len, int pos, int p[], int p_len) {

	//base case
	if(len == pos) {
		print_powerset(p, p_len);
		return;
	}

	// exclude current element from powerset
	powerset(a, len, pos+1, p, p_len);

	// include current element in powerset
	p[p_len] = a[pos];
	powerset(a, len, pos+1, p, p_len+1);
	return;
}

void main() {
	int a[] = {1, 2, 3};
	int len = sizeof(a)/sizeof(a[0]);
	int p[len];
	powerset(a, len, 0, p, 0);
}

