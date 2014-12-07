#include<stdio.h>

void swap(int a[], int i, int j) {
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
void main() {
	int a[]={1, 2, 3};
	swap(a, 0, 1);
	for(int i=0;i<3; i++) {
		printf("%d ", a[i]);
	}
}
