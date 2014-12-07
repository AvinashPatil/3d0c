#include<stdio.h>



void draw(int row, int col) {
	int sr = 0, er = row-1;
	int sc = 0, ec = col-1;
	char matrix[row][col];
	int i;
	char c = 'O';

	while(sr <= er && sc <= ec) {

		for(int i=sc; i<=ec; i++) {
			matrix[sr][i] = c;
		}

		sr++;

		for(int i=sr; i<=er; i++) {
			matrix[i][ec] = c;
		}

		ec--;

		if(sc != ec) {
			for(int i=ec; i>=sc; i--) {
				matrix[er][i] = c;
			}
			er--;	
		}

		if(sr != er) {
			for(int i=er; i>=sr; i--) {
				matrix[i][sc] = c;
			}
			sc++;
		}
		
		if(c == 'O') {
			c = 'X';
		} else {
			c = 'O';
		}
	}
	
	for(int i=0; i<row; i++) {
		for(int j=0; j<col; j++) {
			printf("%c ", matrix[i][j]);
		}
		printf("\n");
	}
}

void main() {
	draw(6, 7);
}
