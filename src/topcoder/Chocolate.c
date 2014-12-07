/*
http://community.topcoder.com/stat?c=problem_statement&pm=6598
*/


#include<stdio.h>
#define min(a,b) (a<b)?a:b


int minSplitNumber(int w, int h, int tiles, int splits, bool width_split) {

	// base case
	if(w*h == tiles) {
		return splits;
	}
	if(w == 1 || h == 1) {
		return splits;
	}

	return min (minSplitNumber(w-1, h, tiles, splits + 1),
	minSplitNumber(w, h-1, tiles, splits + 1));
}

void main() {
	int res =  minSplitNumber(5, 4, 12, 0);

	printf("Res is %d", res);
}
