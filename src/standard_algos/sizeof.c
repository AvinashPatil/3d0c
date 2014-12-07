#include<stdio.h>
#include<string.h>



void main() {

	int a[] = {1, 2, 3, 4, 5};

	// sizeof(a) gives size of whole array. i.e. 20
	int len = sizeof(a)/ sizeof(a[0]);

	printf("len %d\n", len);

	int b[][2] = 	{{1, 2},
			 {3, 4},
			 {4, 5}};

	// sizeof(b) gives size of whole array. i.e. 24 
	int rows = sizeof(b)/sizeof(b[0]);
	int cols = sizeof(b[0])/sizeof(b[0][0]);
	printf("rows %d cols %d\n", rows, cols);

	char *s[] = 	{"hello",
			  "mister",
			 "how do you do"};

	// HERE sizeof(s) gives only 12 as it has 3 pointers.
	int row = sizeof(s)/sizeof(s[0]);
	int col = strlen(s[0]);
	printf("rows %d cols %d\n", row, col);

}
