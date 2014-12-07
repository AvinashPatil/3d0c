/*
http://community.topcoder.com/stat?c=problem_statement&pm=13035

CORRECT
*/

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

int findmaxrow(char a[], int len) {

	bool alt = true;
	int cur_len = 0;
	int ret = 0; 
	for(int i=0; i<len; i++) {
		if(a[i] != 'X') {
			if(i > 0) {
				alt = alt && (a[i] != a[i-1]);
			}
			if (alt) {
				cur_len++;
				if(ret < cur_len) {
					ret = cur_len;
				}	
			}
		}
		else  {
			cur_len = 0;
		}
	}
	return ret;
}

void get_rows(int start, int end, char a[], int len, char *board[]) {

	for(int row=0; row<len; row++) {

		bool alt = true;
		int col;
		for(col= start; col<=end; col++) {
			if(col > 0) {
				alt = alt && (board[row][col] != board[row][col-1]);
			}
		}

		a[row] = (alt ? board[row][start] : 'X'); //understand this :) 
	}
}	

int maxarea(char *board[], int rows, int cols) {
	
	char row[rows];
	int height, width, area =0; 

	for(int i=0; i<cols; i++) {
		for(int j=0; j<=i;j++) {

			memset(row, 0, sizeof(row) * sizeof(int));
			get_rows(j, i, row, rows, board);
			height = findmaxrow(row, rows);
			width = (i-j) + 1;


			if(area < height*width) {
				area = height*width;
			}
			
		}
	}
	return area;
}

void main() {
	
	char *board[] = 	

{"101", 
 "011", 
 "101", 
 "010"} ;	

	int rows = sizeof(board)/sizeof(board[0]);
	int cols = strlen(board[0]); 


	int res = maxarea (board, rows, cols);
	printf("Max area is %d", res);

}
