/*
http://community.topcoder.com/stat?c=problem_statement&pm=12830
*/


#include<stdio.h>
#include<stdbool.h>

bool check(int C[], int S[], bool X[], bool Y[], int len) {
	int c_x, c_y, s_x, s_y;
	c_x = c_y = s_x = s_y = 0; 

	for(int i=0; i<len; i++) {
		if(X[i] == true) {
			c_x = c_x + C[i];	
			s_x = s_x + S[i];
		}
		if(Y[i] == true) {
	//	else {
			c_y = c_y + C[i];
			s_y = s_y + S[i];
		}
	}
	if((c_x > c_y && s_x > s_y) || (c_x < c_y && s_x < s_y) || (c_x == c_y && s_x == s_y)) {
	//	printf("true \n");
		return true;
	} else  {
		//printf("false %d= %d %d= %d \n", c_x, s_x, c_y, s_y);
		return false;	
	}
}

bool equivalent(int C[], int S[], int len, int pos, bool X[], bool Y[]) {

	//printf("pos %d ", pos);
	// base case
	if(pos == len) {
		return true;
	}

	if((check(C, S, X, Y, len)) == false) {
		return false;
	}
	
	// X and Y will have positions included 

	X[pos] = true;
	Y[pos] = false;
	if(equivalent(C, S, len, pos+1, X, Y) == false) {
		return false;
	}
	X[pos] = false;
	Y[pos] = true;
	if(equivalent(C, S, len, pos+1, X, Y) == false) {
		return false;
	}
	X[pos] = false;
	Y[pos] = false;
	if(equivalent(C, S, len, pos+1, X, Y) == false) {
		return false;
	}
	
	return true;

}	

void main() {

	int C[] = 
	{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
	//{30, 50, 20};
	
	int S[] = 
	{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
	//{49, 50, 1};

	int len = sizeof(C)/sizeof(C[0]);

	bool X[len];
	bool Y[len];

	for(int i=0; i<len; i++) {
		X[i] = Y[i] = false;
	}

	if(equivalent(C, S, len, 0, X, Y)){
		printf("Equivalent");
	} else {
		printf("Not equivalent");
	}
}

