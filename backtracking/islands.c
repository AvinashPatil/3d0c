/* Program to calculate the number of islands in a the given matrix
*/

#include<stdio.h>
#include<stdbool.h>

#define ROW 5
#define COL 5 


int row_array[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int col_array[] = {-1, 0 , 1, 1, 1, 0, -1, -1};

bool isSafe(int a[][COL], int i, int j) {
	if(i<0 || i>=ROW || j<0 || j>=COL || (a[i][j] == 0))
		return false;
	return true;	
}

void DFS(int a[][COL], int i, int j) {
	// visit this node
	a[i][j] = 0;

	// check neighbours
	for (int k=0; k<8; k++) {
		if(isSafe(a, i+row_array[k], j+col_array[k])) {
			// visit all the neighbours
			DFS(a, i+row_array[k], j+col_array[k]);
		}
	}
}


int islands(int a[][COL]) {
	int count = 0;
	for(int i=0; i<ROW; i++) {
		for(int j=0; j<ROW; j++) {
			if(a[i][j] == 1) {
				DFS(a, i, j);
				count++;
			}
		}
	}
	return count;
}

void main() {
	int a[][COL] = {{1, 0, 0, 0, 1},
		 	{1, 1, 0, 1, 0},
			{0, 0, 0, 0, 0},
			{1, 0, 1, 1, 0},
			{0, 0, 1, 1, 0}};

	int res = islands(a);
	printf("Number of islands is %d", res);
}



