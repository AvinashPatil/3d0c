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

void combine(int a[], int temp[], int p, int q, int r, int s) {

	printf("Called combine for %d %d %d %d\n", p, q, r, s);

        int i = p;
        while(p <= q && r <= s) {
                if(a[r] < a[p]) {
                        temp[i++] = a[r++];
                } else {
                        temp[i++] = a[p++];
                }
        }

        while(p <= q) {
                temp[i++] = a[p++];
        }

        while(r <= s) {
                temp[i++] = a[r++];
	}
}

void merge(int a[], int temp[], int start, int end) {

	if(start < end) {
                int mid = start + (end - start)/2;

		//if((mid - start) > 5) {
               	merge(a, temp, start, mid);
               	merge(a, temp, mid+1, end);
	/*	} else {
			quick(a, start, mid);
			quick(a, mid+1, end);
		}*/
                combine(a, temp, start, mid, mid+1, end);
        }
}

int main() {

	int a[] = {3, 10, 6, 15, 22, 1, 40, 8, 21, 7, 8, 45, 31, 37, 20,  9, 18, 2, 23, 67, 29, 200, 24, 34, 56, 12, 5, 88, 44, 32, 46, 64,31,87,364,31, 66,31,564,6,6654,546,8,132,58,56,9,56,32,54,12,64,132,32,956,98,36,546,13,978,3,31,46};

	int len = sizeof(a) / sizeof(a[0]);
	int temp[len];
	merge(a, temp, 0, len-1);

	for(int i=0; i<len; i++)
		printf("%d ", temp[i]);
	return 0;
}
