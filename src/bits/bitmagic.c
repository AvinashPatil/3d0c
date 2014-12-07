#include<stdio.h>
#include<limits.h>

int next_pow_2(int n) {

	if(n&(n-1) == 0) {
		return n;
	}
	int p = 1;
	while(p<n) {
		p = p << 1;
	}
	return p;
}

int parity(unsigned int i) {

	int count = 0;
	while(i>0) {
		if(i&1) {
			count++;
		}
		i = i >> 1;
	}
	return count;
}


int multiply7(int i) {

	return ((i<<3) - i);
}

int rightmostone(int i) {

	int index = 0;
	while(i>0) {
		if(i&1) {
			return index;
		}
		else {
			i = i >> 1;
			index++;
		}
	}
}

int oddoccur(int a[], int len) {

	int xor=0;

	for(int i=0; i<len; i++) {
		xor = xor ^ a[i];
	}

	return xor;
}

void checkoverflow(int a, int b) {
	int res;
	if(a > 0 &&  b > 0) {
		res = a+b;
		if(res < 0) {
			printf("OVERFLOW\n");
		}
	}
	if(a < 0 &&  b < 0) {
		res = a+b;
		if(res > 0) {
			printf("OVERFLOW\n");
		}
	}
}

void checkendianness() {
	unsigned int a= 1; // 1 is LSB	
	char *p = (char *)&a; // p points to lower address(THIS FACT DOES NOT CHANGE)
	
	if(*p == 1) {
		// LSB is at smallest address
		printf(" Little Endian\n");

	} else {

		// As per handwriting from lower address to higher. 
		printf(" Big Endian\n");
	}

}

int reverse_bits(int n) {
	int m = 0;
	for(int i=0; i < sizeof(int) *8; i++) {
		if((n>>i) & 1) {
			m  = m | (1 << (((sizeof(int) *8) -1) - i));
		}
	}
	return m;
}

int bitflips(int i, int j) {
	int xor = i ^ j;
	
	int count= 0;
	while(xor > 0) {
		if(xor & 1) {
			count++;
		}
		xor = xor >> 1;
	}
	return count;
}


int rotateleft(int i, int pos) {

	int NO_BITS = sizeof(int) * 8;

	int temp = 0;
	temp = i;
	temp = temp >> (NO_BITS - pos);
	i = i<<pos;
	i = i | temp;
	return i;
}


void main() {

	int i = 9;
	printf("Next powerof2 of %d is %d \n", i, next_pow_2(i));
	printf("Parity of %d is %d \n", i, parity(i));
	printf("i*7 is %d \n",multiply7(i));
	printf("position of right most 1 in %d is %d \n", i, rightmostone(i));

	int a[] =  {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5};
	int len = sizeof(a)/sizeof(a[0]);

	printf("Number occuring odd number times in a[] is %d\n", oddoccur(a, len));
	checkoverflow(INT_MAX, i);

	checkendianness();
	printf("Reverse bits for 2 is %d\n",reverse_bits(2));
	printf("Bit flips required to convert 5 to 9 is %d", bitflips(5,9));
	printf("leftrotate 16 by 30 positions is %d", rotateleft(16, 30));
	
}
