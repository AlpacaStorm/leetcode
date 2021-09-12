#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void main() {
	int arr[10][10];
	for(int i=0;i<10;i++) {
		printf("%X\n",&arr[i]);
		for(int j=0;j<10;j++) {
			printf("%X\n",&arr[i][j]);
		}
	}
}
