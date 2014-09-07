#include<stdio.h>
#include<stdbool.h>
#define N 9


bool isSafebox(int grid[N][N], int row, int col, int num) {
	for(int i=row; i<row+3; i++) {
		for(int j=col; j<col+3; j++) {
			if(grid[i][j] == num) {
				return false;
			}
		}
	}
	return true;
}

bool isSafecol(int grid[N][N], int col, int num) {
	for(int i=0; i<N; i++) {
		if(grid[i][col] == num) {
			return false;
		}
	}
	return true;
}

bool isSaferow(int grid[N][N], int row, int num) {
	for(int i=0; i<N; i++) {
		if(grid[row][i] == num) {
			return false;
		}
	}
	return true;
}
	
bool isSafe(int grid[N][N], int row, int col, int num) {
	if(!isSaferow(grid, row, num) || !isSafecol(grid, col, num) || !isSafebox(grid, row -(row%3), col- (col%3), num)) {
		return false;
	}
	return true;
}
bool FindUnassigned(int grid[N][N], int *row, int *col) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(grid[i][j] == 0) {
				*row = i;
				*col = j;	
				return true;
			}
		}
	}
	return false;
}

bool solve(int grid[N][N]) {

	int row, col;

	if(!FindUnassigned(grid, &row, &col)) {
		return true;
	}

	for(int num=1; num<=9; num++) {
		if(isSafe(grid, row, col, num)) {
			grid[row][col] = num;
			if(solve(grid) == true) {
				return true;
			}
			grid[row][col] = 0; // backtrack
		}
	}
	return false;
	
}

void print(int grid[N][N]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}	
}

void main() {

	int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
	if(solve(grid)) {
		print(grid);
	} else {
		printf("No solution");
	}
}
