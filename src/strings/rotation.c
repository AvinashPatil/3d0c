/* Program to check if a string is rotation of other

Learnings: 
String functions  

strcat(str1, str2)  = concatenate and return null terminated  str1 = str1 + str2
ptr = strstr(temp, str)) returns a pointer where str starts in temp. Else NULL
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int isrotate(char str1[], char str2[]){
	
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	char * temp = (char *) malloc(len1+len2+1);

	memset(temp, 0, (len1+len2+1));
	//temp[0] = '\0';

	temp = strcat(temp, str1);
	temp = strcat(temp, str2);

	char *res = strstr(temp, str2);
	
	if(res) {
		return 1;
	} else {
		return 0;	
	}
}

void main() {

	char a[] = "roatatethis";
	char b[] = "thisrotate";

	printf("The strings are rotation %d ",isrotate(a, b));
}
