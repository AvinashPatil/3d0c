/*
Learnings:
	1. In array of pointers to strings
		sizeof(a)  number of pointers * sizeof each pointer
		sizeof(a[0]) size of each pointer		
	2. empty string is "" and not NULL
	3. Do not forget to add low < high condition in binary search. 
*/

#include<stdio.h>
#include<string.h>
	
void findstring (char *a[], int low , int high, char *str) {

	if(low < high) {

		int mid = low + (high - low) / 2;
		if(a[mid] == "") {
			int left = mid -1;
			int right = mid + 1;

			while(left >= low && right < high) {
				if(a[left] != NULL) {
					mid = left;
					break;
				}
				if(a[right] != NULL) {
					mid = right;
					break;
				}
				left--;
				right++;
			}
		}

		int cmp = strcmp(str, a[mid]);
		//printf("a[mid] = %s \n str= %s \n", a[mid], str);

		if(cmp == 0) {
			printf("found string at %d", mid);
			return;
		}

		if(cmp<0) {
			findstring(a, low, mid -1, str);
		} else {
			findstring(a, mid +1, high, str);
		}
	}
}


void main() {

	char *a[] = {"ab", "", "bs"};

	//printf("%d  %d  %d",sizeof(a), sizeof(a[0]), sizeof(*a[0]));
	
	for(int i=0; i<(sizeof(a)/sizeof a[0]); i++) {
		printf("%s\n", a[i]);
	}

	int len = (sizeof(a)/sizeof a[0]);

	findstring(a, 0, len, "bs");
}
