#include <stdio.h>
#include <stdlib.h>



int longestValidParentheses(char* s) {
	int max = 0;
	int l=0;
	int r=0;
	int len = strlen(s);
	for(int i=0;i<len;i++) {
		if(*(s+i)=='(') {
			l++;
		}
		else {
			r++;
		}
		if(r>l)
			r=l=0;
		else if(r==l && max < r+r)
			max = r+r;
	}
	l=r=0;
	for(int i=len-1;i>=0;i--) {
		if(*(s+i)==')') {
			r++;
		}
		else {
			l++;
		}
		if(l>r)
			l=r=0;
		else if(l==r && max < l+l)
			max = l+l;
	}
	return max;
}

int main() {
	char str[100] = ")()())";
	printf("%d\n",longestValidParentheses(str));
	return 0;
}
