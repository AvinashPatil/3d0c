#include<stdio.h>

void swap(int a[], int m, int n) {
	int t;
	t = a[m];
	a[m] = a[n];
	a[n] = t; 

	return;
}

void quick(int a[], int low, int high) {

	if(low<=high) {
		int temp = a[low]; // copy this element
		int p = low;  // this is partition index 

		for(int i=low; i<=high; i++) { //including low and high indices
			if(a[i] < temp) {
				p++;
				swap(a, i, p);
			}
		}

		swap(a, low, p);

		quick(a, low, p-1);
		quick(a, p+1, high);
	}
}

int main() {

	int a[] = {3, 6, 1, 4, 7, 8, 9, 2, 5};

	int len = sizeof(a) / sizeof(a[0]);
	quick(a, 0, len-1);

	for(int i=0; i<len; i++)
		printf("%d", a[i]);
	return 0;
}
