/* This programs gives substring of a string which is
	LONGEST WITHOUT REPEATING CHARACTERS
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 256


void findlongest(char a[], int len) {
	int prev_instance[MAX];	

	memset(prev_instance, -1, sizeof(prev_instance));

	int prev = 0;
	int cur_len = 0;
	int max_len = 0;	
	prev_instance[a[0]] = 0; // initialize prv instance of 0th char

	for(int i = 1; i<len; i++) {
		if((prev_instance[a[i]] == -1) || (i - cur_len  > prev_instance[a[i]])) {
			// this means this char has not been visited or its not part of cur string
			// we can include this char

			cur_len++;
		} else {
			// update max_len
			if(cur_len > max_len) {
				max_len = cur_len;
			}
			// update curlen
			cur_len = (i - prev_instance[a[i]]);	
		}
		prev_instance[a[i]] = i;
	}
	
	if(cur_len > max_len)
		max_len = cur_len;

	printf("Max string len is  %d", max_len);
}

void main() {

	char a[] = "geeksforgeeks";
	int len = sizeof(a)/ sizeof(a[0]);
	findlongest(a, len);
}
