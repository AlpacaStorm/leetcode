#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * nearestPalindromic(char * n){
	int l = strlen(n);
	if(l==1) {
		if(*n == '0') *n = '1';
		else (*n)--;
		return n;
	}
	int hl = l/2;
	bool isP = true;
	for(int i=0;i<hl;i++) {
		if(*(n+i) != *(n+l-i-1)) {
			isP = false;
			break;
		}
	}
	if(isP) {
		if(l%2 == 0) {
			//case 11
			if(l == 2 && *n == '1') {
				*n = '9';
				*(n+1) = '\0';
			}
			else {
				(*(n+hl-1))--;
				*(n+hl) = *(n+hl-1);
				for(int i=0;*(n+hl-i-1)=='0'-1;i++) {
					*(n+hl-i-1) = *(n+hl+i) = '9';
					(*(n+hl-i-2))--;
					*(n+hl+i+1) = *(n+hl-i-2);
				}
			}
		}
		else {
			if(*(n+hl)=='0') *(n+hl) = '1';
			else (*(n+hl))--;
		}
		return n;
	}
	
}

int main() {
	char str[20] = "9";
	printf("%s\n",nearestPalindromic(str));
}
