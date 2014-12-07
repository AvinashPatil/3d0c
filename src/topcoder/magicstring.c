#include<stdio.h>
#include<string.h>
#include<stdbool.h>


void process_str(char str[], int right[], int left[], int len, int *l_len, int *r_len) {

	*r_len = -1;
	*l_len = -1;

	for(int i=0; i<len; i++) {

		if(str[i] == '>') {
			right[++(*r_len)] = i;
		}
		if(str[i] == '<') {
			left[++(*l_len)] = i;
		}
	}
	return;

}

// find the position of first element in array which is greater than k
int bin_search(int a[], int start, int end, int k) {

	/*if(start > end) {
		int mid = start + (end - start)/2;

		if(mid == 0 && a[mid] >  k) {
			return mid;
		}
		else if((a[mid] - 1 < k) && (a[mid] > k)) {
			return mid;
		} 
		else if(mid < k) {
			// search right half
			return bin_search(a, mid+1, end, k);
		} else {
			// search left half
			return bin_search(a, start, mid -1, k);
		}

	}*/
	for(int i=start; i<=end;i++) {
		if(a[i] > k) {
			return i;
		}
	}
}

bool check_if_exists(int a[], int len, int item, int rem) {

	if(item > a[len]) {
		return false;
	}

	if(item < a[0]) {
		return true;
	}	

	int pos = bin_search(a, 0, len, item);
	if((len - pos) >= rem) {
		return true;
	}
	return false;
}

int find_magic(int right[], int left[], int l_len, int r_len) {

	int magic_len = 0;
	for(int i=0; i<=r_len; i++) {
		if(check_if_exists(left, l_len, right[i], i) == true) {
			if( magic_len < i )
				 magic_len = i;
		}
	}
	return magic_len * 2;
}

void main() {
	char str[]= "<><><<>";
	//char str[]= ">>><<<";
	int len = strlen(str);

	int right[len];
	int left[len];
	
	for(int i=0; i<len; i++) {
		right[i] = left[i] = -1;
	}
	int l_len, r_len;
	process_str(str, right, left, len, &l_len, &r_len);
	l_len++;
	r_len++;
	printf("%d %d", l_len, r_len);
	int res = find_magic(right, left, l_len, r_len);
	printf("Magic str len is %d", res);
}
