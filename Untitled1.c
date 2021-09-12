#include <stdio.h>
#include <stdlib.h>

int main() {
	int a[3] = {1,2,3};
	printf("%X	%X\n",a,&a);
	int *b = (int*) malloc(sizeof(int)*3);
	b[0]=1;
	b[1]=2;
	b[2]=3;
	printf("%X	%X\n",b,&b);
}
