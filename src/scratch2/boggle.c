/*In a 2D array (M x N, in the given ex. 3×3) of numbers,
 find the strictly increasing path from the specified origin cell (1,0) to
the specified destination cell (0, 2). Array may contain duplicates, and solution
should work with the dups. */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define n_row 8
#define n_col 8
#define MAX 10

int row[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int col[] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool isSafe(int matrix[][3], int s_x, int s_y, int path[], int pos) {

	if(s_x<0 || s_y > 2) {
		return false;
	}

	if(matrix[s_x][s_y] >= path[pos]) {
		return false;
	}

	return true;
}

int find_path(int matrix[][3], int s_x, int s_y, int d_x, int d_y, int path[], int pos) {

		printf(" %d %d %d %d \n", s_x, s_y, d_x, d_y);
	if(s_x==d_x && s_y==d_y) {

		//printf(" %d %d %d %d ", s_x, s_y, d_x, d_y);

		path[pos] = matrix[d_x][d_y];
		return pos;
	}

	for(int i=0; i<n_row; i++) {
		for(int j=0; j<n_col; j++) {
			if(isSafe(matrix, s_x+row[i], s_y+col[j], path, pos)) {
				path[pos] =  matrix[s_x+row[i]][s_y+col[j]];
				find_path(matrix, s_x+row[i], s_y+col[j], d_x, d_y, path, pos++);
			}
		}
	}

	return -1;
}

void main() {

	int matrix[3][3] = {
			{1, 1, 2},
			{-1, 3, 3},
			{4, 4, 4}
			};
	int path[MAX] = {0};

	int len = find_path(matrix, 0, 1, 2, 2, path, 0);

	printf(" %d", len);
	for(int i=0; i<len; i++) {
		printf("%d ", path[i]);
	}
}


