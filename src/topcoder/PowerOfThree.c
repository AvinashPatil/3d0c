/*
http://community.topcoder.com/stat?c=problem_statement&pm=12917
*/

#include<stdio.h>
#include<stdbool.h>


int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, -1}
		};

int pow3(int x, int y ) {
	for(int i=1; i<y; i++) {
		x = x*x;
	}
	return x;
}

bool ableToGet(int x_d, int y_d, int x, int y, int step, int p) {
	// base case
	if(x_d == x && y_d == y) {
		return true;
	}
	if(step == 20) {
		return false;
	}
	for(int i=0; i<4; i++) {
		if(ableToGet(x_d, y_d, x + (dir[i][0]* p), y + (dir[i][1] * p), step +1, p*3))
			return true;
	}
	return false;
}	
void main() {

	int x_s = 0;
	int y_s = 0;

	int x_d = 1;
	int y_d = 9;

	if(ableToGet(x_d, y_d, x_s, y_s, 0, 1)) {
		printf("Possible");
	} else {
		printf("ImPossible");
	}
}
