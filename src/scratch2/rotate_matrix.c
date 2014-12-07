/*
Given an image, how will you turn it by 90 degrees?



Algorithm:

for(int r=0; r<m: r++) {
	for(int c=0; c<n; c++) {
		target[c][m-r-1] = source[r][c];
	}
}

*/

#include<stdio.h>
#include<stdlib.h>

#define ROW 4
#define COL 4


void display(int matrix[ROW][COL]) {

	for(int i=0; i<ROW; i++) {
		for(int j=0; j<COL; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void rotate(int source[ROW][COL], int target[ROW][COL]) {
	for(int r=0; r<ROW; r++) {
		for(int c=0; c<COL; c++) {
			target[c][ROW-r-1] = source[r][c];
		}
	}
}
void main() {
	int source[ROW][COL] = {
		{1,2,3,4}, 
		{5,6,7,8}, 
		{9,10,11,12}
		};
	int target[ROW][COL];

	display(source);
	rotate(source, target);
	printf("\n");
	display(target); 
}

