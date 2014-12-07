/*
http://community.topcoder.com/stat?c=problem_statement&pm=12427

CORRECT!!
*/

#include<stdio.h>
#include<stdlib.h>


int getDist(int T, int a[], int len) {
	int dir[4][2] = {{0, 1}, 
			{1, 0}, 
			{0, -1}, 
			{-1, 0}};	

	int x_o = 0; 
	int y_o = 0;
	
	int x_n = x_o;
	int y_n = y_o;
	int dir_cur = 0;
	for(int t=0; t<T; t++) {
		for(int i=0; i<len; i++) {
			x_n = x_n +  a[i] * dir[dir_cur][0];
			y_n = y_n +  a[i] * dir[dir_cur][1];

			dir_cur = (dir_cur + a[i]) % 4;
		}
	}

	return (abs(x_n - x_o) + abs(y_n - y_o));
}

void main() {
	//int T = 1;
	//int a[] = {1, 2, 3};
	int T = 570;
	int a[] = {2013,2,13,314,271,1414,1732};
	int len = sizeof(a)/ sizeof(a[0]);


	int res = getDist(T, a, len);

	printf("Dist is %d", res);
}


