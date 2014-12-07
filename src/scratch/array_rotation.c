#include<stdio.h>

void reverse(int a[], int start, int end) {

	int temp;
	while(start<end) {
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

void rotate(int a[], int pos, int len) {
	reverse(a, 0, pos-1);
	reverse(a, pos, len-1);
	reverse(a, 0, len-1);
}

void print(int a[], int len) {
	for(int i=0; i<len; i++) {
		printf("%d ", a[i]);
	}
}

void main() {
	int a[] = {0, 1, 2, 3, 4, 5};
	int len = sizeof(a)/sizeof(a[0]);
	rotate(a, 2, len);
	print(a, len);
}
