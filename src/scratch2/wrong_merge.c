#include<stdio.h>
#include<stdbool.h>


void combine(int a[], int i, int j, int l, int m, int temp[]) {
	int x = i;
	while(i<=j && l<=m) {
		if(a[i] < a[l]) {
			temp[x++] = a[i++];
		} else {
			temp[x++] = a[l++];
		}
	}

	while(i != j) {
		temp[x++] = a[i++];
	}

	while(l != m) {
		temp[x++] = a[l++];
	}
	return;
	
}

void merge(int a[], int low, int high, int temp[]) {

	if(low<high) {

		int mid = (low+high)/2; //low + (high - low)/2;
		merge(a, low, mid-1, temp);
		merge(a, mid+1, high, temp);
		combine(a, low, mid-1, mid+1, high, temp);
	}
}


void main() {
	int a[] = {6, 7, 3, 4, 6, 9, 3, 1};
	int len = sizeof(a)/sizeof(a[0]);
	int temp[len];
	merge(a, 0, len-1, temp);
	
}

