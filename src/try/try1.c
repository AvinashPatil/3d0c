#include<stdio.h>
#include<string.h>	
#include<stdbool.h>
#define MAX 100



void main() {
	
	int a, b;
	a = 100;
	b = 3;


	int x, y;
	
	int count = 0;
	int flag = false;	
	char str[MAX];
	int index = 0;	

	while (true) {

		x = a / b; // 33
		
		//printf("%d", x);
		str[index++] = '0' + x;

		// we have to print the decimal part only once
		if(!flag) {
			//printf(".");
			str[index++] = '.';
			flag = true;
		}

		y = a % b; // y = 1
		
		// check if the fractional part is present
		if (y != 0) {
			a = y * 10; //  left shift the fractional didgits one by one  
			while(a < b) {
				// make sure we haev enough big number
				// add 0 for each left shift		
				a = y * 10;
				//printf("0");
				str[index++] = '0';
			}
			if(++count > 5) {
				break;
			}
		} else {
			str[index++] = '0';
		//	printf("0");
		}
	}
	str[index] = '\0';
	printf("%s", str);	
}


void main1() {
	float a = 100;
	int b = 3;
	int c = a;
	char str1[MAX];
	char str2[MAX];

	int i = 0;
	while(c > 0) {
		str1[i++] = '0' + (c % b);
		c = c / b;
		a = a / b;
	}
	str1[i] = '\0';
	
	i = 0;
	int count = 0;
	while(a > 0) {
		a = a * 10;
		c = a;
		str2[i] =  '0' + (c % 10);
		if(i > 0 && str2[i-1] == str2[i]) {
			count++;
		} else {
			count = 0;
		}
		
		if(count > 5) {
			str2[i-2] = ')';
			str2[i-4] = '(';
			str2[i-1] = '\0';
			break;	
		}
		a = a / 10;
		i++;
	}

	int len = strlen(str1);
	for(i = len - 1; i >=0; i--) {
		printf("%c",str1[i]);
	}		
	printf(".");
	printf("%s", str2);
	
}
