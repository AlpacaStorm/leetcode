#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
	int c = heightMapColSize[0];
	int ** waterMap = (int**) malloc(sizeof(int) * heightMapSize * c);
	bool ** searched = (bool**) calloc(heightMapSize * c,sizeof(bool));
	for(int i=0;i<heightMapSize;i++) {
		for(int j=0;j<c;j++) {
			if(!i || !j) {
				*(waterMap+i*c+j) = *(heightMap+i*c+j);
			}
			else if(!*(searched+i*c+j)) {
				int level = *(heightMap+(i-1)*c+j) < *(heightMap+i*c+(j-1)) ? *(heightMap+(i-1)*c+j) : *(heightMap+i*c+(j-1));
				if()
			}
		}
	}
	for(int i=heightMapSize-1;i>=0;i--) {
		for(int j=c-1;j>=0;j--) {
			if(i==heightMapSize-1||) 
		}
	}
	return 0;
}
int main() {
	int heightMapColSize[3] = {3,3,3};
	int heightMap[3][3] = {{3,3,3},{3,3,3},{3,3,3}};
	int ans = trapRainWater(heightMap,3,heightMapColSize);
}
1 4 3 1 3 2
3 2 1 1 2 4
2 3 3 2 3 1 

1 4 3 1 3 2
3 3 3 3 3 4
2 3 3 2 3 1
 
