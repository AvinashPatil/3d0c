/*
http://community.topcoder.com/stat?c=problem_statement&pm=10543
CORRECT
*/

#include<stdio.h>
#include<limits.h>
#define min(a,b) ((a<b)?a:b)

int printSmiles(int smiles, int ops, int window, int clip) {
	// base case

	//printf(" %d %d %d %d \n", smiles, ops, window, clip);
	if(window == smiles) {
		return ops;
	}
	if(ops >= smiles) {
		return INT_MAX;
	}	
	if(window <1) {
		return INT_MAX;
	}	

	if(clip > smiles) {
		return INT_MAX;
	}

	int r1 = printSmiles(smiles, ops+1, window, window); // copy window to clipboard
	int r2 = printSmiles(smiles, ops+1, window+clip, clip); // paste clipboard to window 
	int r3 = printSmiles(smiles, ops+1, window -1, clip); // delete 1 item from window 

	
	//printf(" %d %d %d \n", r1, r2, r3);
	return min(r1, min(r2, r3));
}
	
void main() {

	int res = printSmiles(8, 0, 1, 0);
	printf("ops required %d", res);

}
