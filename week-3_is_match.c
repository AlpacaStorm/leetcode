#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



bool isMatch(char * s, char * p){
	char *ss,*sp;
	bool star = false;
	if(*p == '\0') return *s == '\0';
	while(true) {
		if(*p == '*') {
			while(*p == '*') p++;
			star = true;
			sp = p;
			ss = s;
		}
		if(*p == '\0') {
			if(*(p-1)=='*' || *s == '\0') return true;
			else if(star){
				ss++;
				s = ss;
				p = sp;
			}
			else {
				return false;
			}
		}
		else if(*s == '\0') {
			return false;
		}
		if(*p == '*');
		else if(*s == *p || *p == '?') {
			s++;
			p++;
		}
		else if(star) {
			ss++;
			s = ss;
			p = sp;
		}
		else {
			return false;
		}
		
		
	}
}

int main() {

	bool ans = isMatch("","");
	if(ans) {
		printf("True\n");
	}
	else {
		printf("False\n");
	}
}
