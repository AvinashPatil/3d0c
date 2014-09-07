/* Take the rat from (0, 0) to (N, N in a maze)
*/

#include<stdio.h>
#include<stdbool.h>

#define N 4

int row[] = {0, 1, 1};
int col[] = {1, 1, 0};

bool isSafe(int maze[][N], int x, int y, int sol[][N]) {
	
	if(x < 0 || y>=N ) {
		return false;
	}

	if(maze[x][y] == 0 || sol[x][y] == 1) {
		return false;
	}

	return true;
}	

bool solve_maze_util(int maze[][N], int x, int y, int sol[][N]) {

	// base case	
	if(x==N-1 && y== N-1) {
		return true;
	}
	
	for(int k=0; k<3; k++) {
		if(isSafe(maze, x+row[k], y+col[k], sol)) {

			sol[x+row[k]][y+col[k]] = 1;

			if(solve_maze_util(maze, x+row[k], y+col[k], sol)) {
				return true;
			}

			sol[x+row[k]][y+col[k]] = 0;
		}
	}
	return false;
}

void print_sol(int sol[][N]) {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			printf("%d", sol[i][j]);
		}
		printf("\n");
	}
}

void solve_maze(int maze[][N]) {

	int sol[N][N] = {0};
	
	sol[0][0] = 1;
	
	if(solve_maze_util(maze, 0, 0, sol)) {
		print_sol(sol);
	} else {
		printf("solution does not exixts");
	}
}	

void main() {
	
	// 1 means open
	// 0 means block
	
	int maze[N][N] =  
    {   {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

	solve_maze(maze);

}
