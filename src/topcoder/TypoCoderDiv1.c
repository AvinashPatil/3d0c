/*
http://community.topcoder.com/stat?c=problem_statement&pm=12924

CORRECT
*/


#include<stdio.h>
#define limit 2200
#define max(a,b) (a>b)?a:b

int getmax(int D[], int len, int X, int cur_pos, int change, int table[len][limit]) {

	//base case
	if(cur_pos== len) {
		return change;
	}
	if(X < limit-1 && table[cur_pos][X-1] > 0) {
		return table[cur_pos][X-1];
	}

	int s, d;
	s = d = 0;

	if(X < limit || cur_pos == len-1) { 
		s = getmax(D, len, X+D[cur_pos], cur_pos + 1, ((X<limit && X+D[cur_pos]>=limit))?change+1:change, table);
	}

	d = getmax(D, len, X-D[cur_pos], cur_pos + 1, ((X>=limit && X-D[cur_pos]<limit))?change+1:change, table);

	if(X < limit-1)
		table[cur_pos][X-1] = max(s, d); 
	return max(s, d);

}

/*int getmax(int D[], int len, int X) {
	int change = 0;
		
	for(int i=0; i<len; i++) {

		// if We are brown coder we want to become ceil
		if(X >= limit) {
			change++;
			X = min(0, X-D[i]);
			continue;
		}
		// now its sure that we are a Ceil coder
		// lets check if we can become Brown and in next step become ceil again

		if(X+D[i] >= limit) {
			// if this is last element
			if(i == len -1 || (X+D[i]-D[i+1] < limit)) {
				X += D[i];
				change++;
				continue;
			}
		}
		// we can not skip a step
		X = min(0, X-D[i]);

	}
	return change;
}
*/
void main() {
	//int D[] = {100,200,100,1,1};
	int D[] = {34,64,43,14,58,30,2,16,90,58,35,55,46,24,14,73,96,13,9,42,64,36,89,42,42,64,52,68,53,76,52,54,23,88,32,52,28,96,70,32,26,3,23,78,47,23,54,30,86,32};

	int len = sizeof(D)/ sizeof(D[0]);
	int X = 1328;

	int table[len][limit];
	for(int i=0; i<len; i++) {
		for(int j=0; j<limit; j++) {
			table[i][j] = 0;
		}
	}

	int res = getmax(D, len, X, 0, 0, table);
	printf("max colr chnages is %d", res);
}

