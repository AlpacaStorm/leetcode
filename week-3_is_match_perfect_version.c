#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char * s, char * p){
	char *ss = s,*sp = NULL;
	while(*s) {
		if(*s == *p || *p == '?') {
			s++;
			p++;
			continue;
		}
		if(*p == '*') {
			sp = ++p;
			ss = s;
			continue;
		}
		if(sp) {
			s = ++ss;
			p = sp;
			continue;
		}
		return false;
	}
	while(*p=='*') p++;
	return !*p;
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
