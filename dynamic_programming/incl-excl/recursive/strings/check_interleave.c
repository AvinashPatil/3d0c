/* Program to check if C is interleaving of A and B

A = abcd
B = xyz
C = axbcyzd

There is simple soluion we can do iteratively for this. In which we can check if a char in C is found either in A or B in orderly manner. 

How ever that approact wont work if A and B has some common chars. Like

A = xxy 
B = xxz
C = xxyxxz 


Follwoing solution handles this case
*/

#include<stdio.h>
#include<stdbool.h>


bool check_interleave(char A[], char B[], char C[]) {
	
	// base case  if all strings are empty 
	// we have reached end
	if( !(*A || *B || *C)) {
		return true;
	}
		
	// if only C is empty
	if(*C == '\0') {
		return false;
	}
	
	return ( ((*A == *C) && check_interleave(A+1, B, C+1)) 
		|| (*B == *C ) && check_interleave(A, B+1, C+1));
}	

void main() {
	char A[] = "xxy";
	char B[] = "xxz";
	char C[] = "xyxxz";


	bool res = check_interleave(A, B, C);
	if(res) {
		printf("Interleaved");
	} else {
		printf("Not Interleaved");
	}
 
}
