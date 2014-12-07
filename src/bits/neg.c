/* we can not do negative of number using INT_MAX i.e. overflow
*/

#include<stdio.h>
#include<limits.h>

void main() {
	int a=-5;
	/*unsigned int u = a;
	u += INT_MAX;
	a += INT_MAX;
	printf("%d", a);
*/
	int neg = 0;
	int d = (a<0)?1:-1;
	
	while(a !=0 ) {
		a += d;
		neg += d;
	}
	printf("%d", neg);
}
