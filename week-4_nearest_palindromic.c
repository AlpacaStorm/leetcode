#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void minus(char *n,int index) {
	(*(n+index)) --;
	while(*(n+index)=='0'-1) {
		*(n+index) = '9';
		index--;
		(*(n+index))--;
	}
}
void add(char * n,int index) {
	(*(n+index))++;
	while(*(n+index)=='9'+1) {
		*(n+index) = '0';
		index--;
		(*(n+index))++;
	}
}
char * nearestPalindromic(char * n){
	int l = strlen(n);
	//case 0~9
	if(l==1) {
		if(*n == '0') *n = '1';
		else (*n)--;
		return n;
	}
	//case 10000000000000[0~1]
	if(*n == '1' && (*(n+l-1) == '1' || *(n+l-1) == '0')) {
		bool flag = true;
		for(int i=1;i<l-1;i++) {
			if(*(n+i) != '0') {
				flag = false;
			}
		}
		if(flag) {
			for(int i=0;i<l-1;i++) {
				*(n+i) = '9';
			}
			*(n+l-1) = '\0';
			return n;
		}
	}
	bool nine = true;
	for(int i=0;i<l;i++) {
		if(*(n+i) != '9') {
			nine = false;
		}
	}
	if(nine) {
		char* m=(char*)malloc(sizeof(char)*l+2);
		m[0]=m[l]='1';
		m[l+1]='\0';
		for(int i=1;i<l;i++) {
			m[i]='0';
		}
		return m;
	}
	int hl = l/2;
	bool isP = true;
	for(int i=0;i<hl;i++) {
		if(*(n+i) != *(n+l-i-1)) {
			isP = false;
			break;
		}
	}
	//case palindrom
	if(isP) {
		if(l%2 == 0) {
			(*(n+hl-1))--;
			*(n+hl) = *(n+hl-1);
			for(int i=0;*(n+hl-i-1)=='0'-1;i++) {
				*(n+hl-i-1) = *(n+hl+i) = '9';
				(*(n+hl-i-2))--;
				*(n+hl+i+1) = *(n+hl-i-2);
			}
			
		}
		else {
			if(*(n+hl)=='0') *(n+hl) = '1';
			else (*(n+hl))--;
		}
		return n;
	}
	else {
		int num1,num2,temp,count;
		num1 = 0;
		if(l%2) {
			for(int i=1;i<=hl;i++) {
				num1 *= 10;
				num1 += *(n+hl+i)-*(n+hl-i);
			}
			temp = hl;
			count = 0;
		}
		else {
			for(int i=1;i<=hl;i++) {
				num1 *= 10;
				num1 += *(n+hl+i-1)-*(n+hl-i);
			}
			temp = hl-1;
			count = 1;
		}
	//	printf("num1 : %d\n",num1);
		if(num1>0) {
			//printf("Case 1\n");
			while(*(n+temp)=='9') {
				temp--;
				count++;	
			}
			num2=1;
			for(int i=0;i<hl;i++) {
				num2 *=10;
				if(count) {
					count--;
					num2++;
				}
			}
			num2 = num2-num1;
			//printf("num2 : %d\n",num2);
			if(num2<num1) {
				if(l%2)
					add(n,hl);
				else
					add(n,hl-1);
			}
		}
		else {
			//printf("Case 2\n");
			num1 *= -1;
			while(*(n+temp)=='0') {
				temp--;
				count++;	
			}
			num2=1;
			for(int i=0;i<hl;i++) {
				num2 *=10;
				if(count) {
					count--;
					num2++;
				}
			}
			num2 = num2-num1;
			//printf("num2 : %d\n",num2);
			if(num2<=num1) {
				if(l%2)
					minus(n,hl);
				else
					minus(n,hl-1);
			}
		}
		
		for(int i=0;i<hl;i++) {
			*(n+l-i-1) = *(n+i);
		}
		return n;
	}
}

int main() {
	char str[20] = "11";//9990999 - 9989899
	char* ans = nearestPalindromic(str);
	if(ans)
		printf("%s\n",ans);
	else
		printf("Undefine!\n");
}
