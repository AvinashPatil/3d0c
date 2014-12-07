/* Find k closest values to the given value in array
*/

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>


int find_index(int a[], int l, int h, int val) {
	
	int mid = l+(h-l)/2;

	if(a[mid] == val) {
		return mid;
	}	

	if(a[mid] < val) {
		return find_index(a, mid+1, h, val);
	} else {
		return find_index(a, l, mid-1, val);
	}
}

void find_k_closest(int a[], int len, int val, int k) {

	int index = find_index(a, 0, len-1, val);
	//printf("%d", index);
	int left = index;
	int right = index;

	while(k>0) {
		if(left >0 &&  right<len && abs(a[left-1]-a[index]) < abs(a[right+1]-a[index])) {
			left--;
			k--;
		}

		if(left >0 &&  right<len && abs(a[left-1]-a[index]) > abs(a[right+1]-a[index])) {
			right++;
			k--;
		}
	}

	while(k>0 && left == 0 && right<len) {
		right++;
		k--;
	}

	while(k>0 && right == len-1 && left >0) {
		left--;
		k--;
	}

	for(int i=left; i<=right; i++) {
		printf("%d ", a[i]);
	}
}

void main() {
	int a[] = {12, 16, 22, 30, 35, 39, 42,
               45, 48, 50, 53, 55, 56};
	int len = sizeof(a)/sizeof(a[0]);

	find_k_closest(a, len, 35, 4);
}
