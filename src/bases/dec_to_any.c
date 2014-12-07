#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void reverse(char *str) {
	int len = strlen(str);
	int start = 0;
	int end = len-1;
	char temp;
	while(start < end) {
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	//printf("%s\n", str);
}

char * dec_to_(int num, int base) {

	char chars[] = "0123456789ABCDEFGHIJ";

	char *res = (char *)malloc(MAX);

	int i=0;
	while(num>0) {
		res[i++] = chars[num%base];
		num = num/base;
	}
	res[i] = '\0';
	reverse(res);
	return res;
}

/*int find(char str[], char ch) {
	for(int i=0; i<strlen(str); i++) {
		if (str[i] == ch) {
			return i;
		}
	}
}

int other_to_dec(char *num, int base) {
	int temp= 0;
	char chars[] = "0123456789ABCDEFGHIJ";
	//for(int i=strlen(num) - 1; i>=0; i--) {
	for(int i=0; i<strlen(num); i++) {
		temp= temp*10;
		int index = find(chars, num[i]);
		temp+= (index%base);
	}

	int dec = 0;
	while(temp) {
		dec = dec*10;
		dec += (temp%base);
		temp %= base;
	}
	return dec;
}
*/
void main() {
	
	//printf("%s", dec_to_(100,8));
	char *res = dec_to_(100,8);
	printf(" Dec to other base %s\n", res);
	//printf(" Other base to dec %d\n", other_to_dec(res, 8));

}
