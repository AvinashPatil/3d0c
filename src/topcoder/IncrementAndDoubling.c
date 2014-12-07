#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define min(a,b) a<b?a:b

bool check(int original[], int desired[], int len) {
	for(int i=0; i<len; i++) {
		if(original[i] != desired[i])
			return false;
	}
	return true;
}

int get_ops(int desired[], int original[], int len, int pos, int ops ) {

	if(check(original, desired, len)) {
		return ops;
	}

	if(pos==len) {
		return INT_MAX;
	}

	original[pos] = original[pos] + 1;
	int res1 = get_ops(desired, original, len, pos+1, ops+1);
	original[pos] = original[pos] - 1;
	for(int i=0; i<len; i++) {
		original[i] *= 2;
	}
	int res2 = get_ops(desired, original, len, pos+1, ops+1);

	return min(res1, res2);
}	

void main() {
	//int a[] = {2, 1};
	int a[] = {16, 16, 16};
	int len = sizeof(a)/ sizeof(a[0]);

	int start[len];
	
	for(int i=0; i<len; i++) {
		start[i] = 0;
	}
	int res = get_ops(a, start,  len, 0, 0);

	printf("ops required %d",res);
}
