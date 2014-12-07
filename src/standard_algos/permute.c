/*
Program to print all the permutations of a string.
Repeatations allowed.

e. ip= ABC
op =

ABC
ACB
BAC
BCA
CBA
CAB

*/ 

#include<stdio.h>
#include<string.h>

void swap(char a[], int i ,int j) {
	char temp =a[i];
	a[i] = a[j];
	a[j] = temp;
}	

void permute_without_repeat(char a[], int start, int end) {

	// base case
	if(start == end) {
		printf("%s\n", a);
		return;
	}

	for(int i=start; i<=end; i++) {
		swap(a, start, i);
		permute_without_repeat(a, start+1, end);
		swap(a, start, i); // backtrack
	}
}

void main() {

	char str[] = "ABC";
	int len= strlen(str);
	
	permute_without_repeat(str, 0, len-1);
}
