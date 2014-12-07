/*
http://community.topcoder.com/stat?c=problem_statement&pm=12504

CORRECT
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define L 50



void dfs(char *level[], int rows, int cols, int visited[rows][cols], int cur_row, int cur_col, int ladder) {
		
	// base condition
	if(visited[cur_row][cur_col])
		return;

	visited[cur_row][cur_col] = 1;

	// move to left
	if((cur_col-1) >=0 && level[cur_row][cur_col-1] == 'X') {
		dfs(level, rows, cols, visited, cur_row, cur_col-1, ladder);
	}

	// move to right
	if((cur_col+1) < cols && level[cur_row][cur_col+1] == 'X') {
		dfs(level, rows, cols, visited, cur_row, cur_col+1, ladder);
	}

	// move vertical
	for(int i=0; i<rows; i++) {
		if(level[i][cur_col] == 'X' && abs(cur_row-i) <= ladder) {
			dfs(level, rows, cols, visited, i, cur_col, ladder);
		}
	}
}

int shortestLadder(char *level[], int rows, int cols, int coinRow, int coinCol) {

	int visited[rows][cols];
	

	for(int i=0; i<L; i++) {
		// try for each ladder length
		
		for(int s=0; s<rows; s++) {
			for(int j=0; j<cols; j++) {
				visited[s][j] = 0;
			}
		}

		dfs(level, rows, cols, visited, rows-1, 0, i);

		if(visited[coinRow][coinCol]) {
			return i;
		}

		printf("==============================================\n");
		for(int s=0; s<rows; s++) {
			for(int j=0; j<cols; j++) {
				printf("%d ", visited[s][j]);
			}
			printf("\n");
		}
	}
	return -1;
}

void main() {

	char *level[] = 	

		{"XXXX....",
		"...X.XXX",
		"XXX..X..",
		"......X.",
		"XXXXXXXX"};
	int coinRow = 2; 
	int coinCol = 5;

	int rows = sizeof(level) / sizeof(level[0]);
	int cols = strlen(level[0]);

	//printf(" %d %d ", rows, cols);

	int res = shortestLadder(level, rows, cols, coinRow, coinCol);
	printf("Min ladder length is %d", res);
	
}
