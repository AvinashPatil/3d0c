/*Problem:

Remove duplicate dfrom array

Contraints - Numbers are >=0
after removing mark them -1
maximum INT_MAX
array size can be large


Algo:

1. Cur pointer, iterator
2. Cur starts from 1 iterator will start form 0
3. a[i] == a[cur] then mark a[cur] = -1
4. cur++ and start from i = 0
5. go to step 3
6. remove 
*/
#include<stdio.h>
#include<stdbool.h>

void remove_all_occ(int a[], int len) {

	bool flag;

	for(int i=0; i<len; i++) {
		flag = false;
		for(int j=i+1; j<len; j++) {
			if(a[i] == a[j] && a[i] != -1) {
				a[j] = -1;
				flag = true;
			}
		}
		if(flag == true) {
			a[i] = -1;
		}
	}
	
	for(int i=0; i<len; i++) {
		printf("%d ", a[i]);
	}
}

void main() {
	int a[]= {4,6,3,21,3,5,1,9,4};
	int len = sizeof(a)/sizeof(a[0]);
	remove_all_occ(a, len);
}
